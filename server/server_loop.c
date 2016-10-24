/*
** server_loop.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Mon Jun 30 16:54:14 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 21:11:37 2014 Nathan BIGAIGNON
*/

#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include "server_loop.h"
#include "server_conf_socket.h"
#include "server_add_player.h"
#include "error.h"
#include "server_error.h"
#include "server_commands_client.h"
#include "server_time_controller.h"
#include "server_send_msg.h"
#include "server_stdin_monitoring.h"

int	set_select_attr(t_utils *utils, char *ok)
{
  if ((init_pre_req(utils)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  FD_ZERO(&(SOCKET->master));
  FD_ZERO(&(SOCKET->rdfs));
  FD_SET(0, &(SOCKET->master));
  FD_SET(SOCKET->listener, &(SOCKET->master));
  SOCKET->fdmax = SOCKET->listener;
  *ok = EXIT_SUCCESS;
  return (EXIT_SUCCESS);
}

int			server_loop(t_utils *utils)
{
  int			i;
  struct timeval	timeout;
  char			ok;

  if ((set_select_attr(utils, &ok)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while (ok != QUIT)
    {
      timeout.tv_sec = 0;
      timeout.tv_usec = 1000000 / utils->args->time;
      i = 0;
      SOCKET->rdfs = SOCKET->master;
      if ((select(SOCKET->fdmax + 1, &(SOCKET->rdfs), NULL, NULL, &timeout))
	  == -1)
	return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
      ok = start_scheduled_action(utils);
      while (i <= SOCKET->fdmax && ok != QUIT && ok != -QUIT)
	{
	  memset(SOCKET->buffer, 0, 255);
	  ok = socket_monitoring(utils, i++);
	}
    }
  close(SOCKET->listener);
  return (EXIT_SUCCESS);
}

int	socket_monitoring(t_utils *utils, int i)
{
  if (FD_ISSET(STDIN, &(SOCKET->rdfs)))
    return (stdin_monitoring(utils));
  else
    {
      if (FD_ISSET(i, &(SOCKET->rdfs)))
	{
	  if (i == SOCKET->listener)
	    {
	      if ((new_connection(utils)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	    }
	  else
	    {
	      if ((recv(i, SOCKET->buffer, 255, 0)) <= 0)
		return (recv_error(utils, i));
	      if ((input_controller(utils, i)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	    }
	}
    }
  return (EXIT_SUCCESS);
}

int	new_connection(t_utils *utils)
{
  if ((SOCKET->new = connect_socket(SOCKET)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  FD_SET(SOCKET->new, &(SOCKET->master));
  if (SOCKET->new > SOCKET->fdmax)
    SOCKET->fdmax = SOCKET->new;
  printf("\033[1;32m[CLIENT %d] is now connected.\033[0m\n", SOCKET->new - 3);
  send(SOCKET->new, "BIENVENUE\n", 10, 0);
  return (EXIT_SUCCESS);
}

int		init_pre_req(t_utils *utils)
{
  t_uint	i;

  if ((utils->args->player_in_team = malloc(sizeof(int)
					    * utils->args->nb_team)) == NULL)
    return (EXIT_FAILURE);
  i = 0;
  while (i < utils->args->nb_team)
    {
      utils->args->player_in_team[i] = 0;
      ++i;
    }
  return (EXIT_SUCCESS);
}
