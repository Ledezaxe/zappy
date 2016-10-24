/*
** server_error.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Tue Jul  1 12:15:17 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 19:12:00 2014 Nathan BIGAIGNON
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "server_error.h"
#include "server_send_msg.h"
#include "server_search_func.h"
#include "server_clients_controller.h"
#include "t_monitors.h"
#include "server_search_func.h"
#include "t_players_ptr.h"

int		recv_error(t_utils *utils, int socket)
{
  char		str[255];

  if (is_monitor(SOCKET->monitors, socket) != 0)
    rm_monitors_from_list(SOCKET->monitors, socket);
  else if (is_ia(utils->user, socket) != 0)
    {
      free_player(utils, socket);
      memset(str, 0, 255);
      sprintf(str, "pdi %d\n", socket);
      send_msg_to_monitors(utils, str);
      memset(str, 0, 255);
      sprintf(str, "mort\n");
      send_msg_to_client(socket, str);
    }
  close(socket);
  FD_CLR(socket, &(SOCKET->master));
  if (socket == SOCKET->fdmax)
    SOCKET->fdmax -= 1;
  printf("\033[1;31m[CLIENT %d] is now disconnected.\033[0m\n", socket - 3);
  return (EXIT_SUCCESS);
}

void		free_player(t_utils *utils, int socket)
{
  t_user_list	*tmp;
  t_user_list	*dup;

  tmp = utils->user->tail;
  dup = get_user_from_id(utils, socket);
  utils->args->player_in_team[check_team_name(utils, dup->team)] -= 1;
  remove_player_in_cell(CELL[dup->y][dup->x]->pptr_list_desc, dup);
  if (tmp->id == (t_uint)socket)
    free_player_unique_elem(tmp, utils);
  else
    free_player_replace_ptr(tmp, utils, socket);
  free(dup->inventory);
  free(dup);
}

void	free_player_unique_elem(t_user_list *tmp, t_utils *utils)
{
  if (tmp == utils->user->head)
    {
      utils->user->tail = NULL;
      utils->user->head = NULL;
    }
  else
    utils->user->tail = tmp->next;
}

void	free_player_replace_ptr(t_user_list *tmp, t_utils *utils, int socket)
{
  while (tmp != NULL)
    {
      if (tmp->next->id == (t_uint)socket)
	    {
	      if (tmp->next == utils->user->head)
		{
		  utils->user->head = tmp;
		  tmp->next = NULL;
		}
	      else
		tmp->next = tmp->next->next;
	    }
	  tmp = tmp->next;
    }
}
