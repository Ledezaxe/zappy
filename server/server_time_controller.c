/*
** server_time_controller.c for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Wed Jul  9 18:22:52 2014 Nathan BIGAIGNON
** Last update Sat Jul 12 19:14:07 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include <string.h>
#include "server_commands_client.h"
#include "server_time_controller.h"
#include "server_error.h"
#include "server_random_resources.h"
#include "server_loop.h"

void	clean_action_list(t_user_list *player)
{
  int	i;

  i = 0;
  while (i < 10)
    {
      player->action[i].fct = NULL;
      player->action[i].start = 0;
      ++i;
    }
}

int		register_action(t_user_list *player)
{
  int		i;
  int		y;

  i = player->cursor;
  y = 0;
  while (y < 10)
    {
      if (i == 10)
	i = 0;
      if (player->action[i].start == 0)
	return (i);
      else
	++i;
      ++y;
    }
  return (-1);
}

int		start_scheduled_action(t_utils *utils)
{
  t_user_list	*tmp;
  t_user_list	*dup;
  int		i;

  if (manage_time(utils) == QUIT)
    return (QUIT);
  tmp = utils->user->tail;
  while (tmp != NULL)
    {
      dup = tmp->next;
      i = user_manage_time(utils, tmp);
      if (tmp == NULL)
	tmp = dup;
      if (i == 1)
	return (EXIT_SUCCESS);
      if (time_action_controller(tmp) != -1)
	{
	  if (launch_action(utils, tmp) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int	launch_action(t_utils *utils, t_user_list *tmp)
{
  char	*str;

  str = NULL;
  memset(SOCKET->buffer, 0, 255);
  strcpy(SOCKET->buffer, tmp->action[tmp->cursor].buff);
  if ((str = tmp->action[tmp->cursor].fct(tmp, utils)) == NULL)
    {
      tmp->action[tmp->cursor].fct = NULL;
      tmp->action[tmp->cursor].start = 0;
      tmp->cursor += 1;
      if (tmp->cursor == 10)
	tmp->cursor = 0;
      return (EXIT_FAILURE);
    }
  send(tmp->id, str, strlen(str), 0);
  free(str);
  tmp->action[tmp->cursor].fct = NULL;
  tmp->action[tmp->cursor].start = 0;
  tmp->cursor += 1;
  if (tmp->cursor == 10)
    tmp->cursor = 0;
  return (EXIT_SUCCESS);
}

int	time_action_controller(t_user_list *tmp)
{
  if (tmp->cursor == 10)
    tmp->cursor = 0;
  if (tmp->action[tmp->cursor].fct != NULL)
    {
      if (tmp->action[tmp->cursor].start != 0)
	tmp->action[tmp->cursor].start -= 1;
      if (tmp->action[tmp->cursor].start == 0)
	return (1);
    }
  return (-1);
}
