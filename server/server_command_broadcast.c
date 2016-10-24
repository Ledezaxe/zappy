/*
** server_command_broadcast.c for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Mon Jun 30 17:04:42 2014 Max Prudhomme
** Last update Sun Jul 13 22:26:14 2014 Nathan BIGAIGNON
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "server_command_broadcast.h"
#include "server_command_watch.h"
#include "server_send_msg.h"
#include "server_search_func.h"

char	*cmd_broadcast(t_user_list *user, t_utils *utils)
{
  char	*str;
  char	tmp[255];

  if ((str = malloc(sizeof(char) * 3 + 1)) == NULL)
    {
      std_raise_error(__FUNCTION__, -1);
      return (NULL);
    }
  strcpy(str, "ok\n");
  if (send_msg_to_users(utils, user) == -1)
    return (NULL);
  sprintf(tmp, "pbc %d %s", user->id, &SOCKET->buffer[10]);
  send_msg_to_monitors(utils, tmp);
  return (str);
}

int		send_msg_to_users(t_utils *utils, t_user_list *user)
{
  t_user_list	*player;
  int		distance[4];
  int		x;
  int		y;
  int		cell;

  player = utils->user->tail;
  while (player != NULL)
    {
      if (player != user)
	{
	  distance[TOP] = distance_from_top(0, player->y, user->y, utils);
	  distance[DOWN] = distance_from_bottom(0, player->y, user->y, utils);
	  distance[LEFT] = distance_from_left(0, player->x, user->x, utils);
	  distance[RIGHT] = distance_from_right(0, player->x, user->x, utils);
	  x = player->x;
	  y = player->y;
	  find_prev_cell(&x, &y, distance, utils);
	  cell = find_cell_pos_player(player, x, y, utils);
	  if (broadcast_msg(utils, player->id, cell) == -1)
	    return (-1);
	}
      player = player->next;
    }
  return (0);
}

void	find_prev_cell(int *x, int *y, int *distance, t_utils *utils)
{
  if (distance[TOP] == 0 && distance[LEFT] == 0)
    {
      *x = *x;
      *y = *y;
    }
  else
    {
      if (distance[TOP] == 0)
	deplace_cell_right_left(x, distance, utils);
      else if (distance[LEFT] == 0)
	deplace_cell_top_down(y, distance, utils);
      else
	if (rand() % 2)
	  deplace_cell_right_left(x, distance, utils);
	else
	  deplace_cell_top_down(y, distance, utils);
    }
}

int	broadcast_msg(t_utils *utils, int socket, int pos)
{
  char	*str;
  int	len;

  len = (strlen(&SOCKET->buffer[10]) + 10) + 1;
  if ((str = malloc(sizeof(char) * len)) == NULL)
    return (std_raise_error(__FUNCTION__, -1));
  sprintf(str, "message %d,%s", pos, &SOCKET->buffer[10]);
  if (get_egg_from_id(utils, socket) == NULL)
    send_msg_to_client(socket, str);
  free(str);
  return (0);
}
