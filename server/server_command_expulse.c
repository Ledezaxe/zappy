/*
** server_command_expulse.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Fri Jul  4 16:07:52 2014 Max Prudhomme
** Last update Sun Jul 13 22:32:33 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "error.h"
#include "t_user_list.h"
#include "t_utils.h"
#include "server_command_broadcast.h"
#include "server_command_forward.h"
#include "server_send_msg.h"
#include "server_commands_client.h"
#include "t_players_ptr.h"
#include "t_monitors.h"
#include "server_search_func.h"

static int	expulse_players(t_cell *cell, t_user_list *user, t_utils *utils)
{
  int		nb;
  t_ptr_players	*player;
  int		pos;
  char		str[255];

  player = cell->pptr_list_desc->tail;
  memset(str, 0, 255);
  sprintf(str, "pex %d\n", user->id);
  send_msg_to_monitors(utils, str);
  nb = 0;
  while (player != NULL)
    {
      if (player->addr != user)
	{
	  memset(str, 0, 255);
	  move_player(utils, player->addr);
	  pos = find_cell_pos_player(player->addr, user->x, user->y, utils);
	  sprintf(str, "deplacement : %d\n", pos);
	  if (get_egg_from_id(utils, player->addr->id) == NULL)
	    send(player->addr->id, str, 255, 0);
	  ++nb;
	}
      player = player->next;
    }
  return (nb);
}

int		send_player_expulse(t_utils *utils, t_user_list *user)
{
  t_monitors	*tmp;

  tmp = SOCKET->monitors->tail;
  while (tmp != NULL)
    {
      memset(SOCKET->buffer, 0, 255);
      sprintf(SOCKET->buffer, "ppo %d\n", user->id);
      cmd_gui_pos_player(tmp->id, utils);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

char	*cmd_expulse(t_user_list *user, t_utils *utils)
{
  char	*str;

  if ((str = malloc(sizeof(char) * 3)) == NULL)
    {
      std_raise_error(__FUNCTION__, -1);
      return (NULL);
    }
  if (expulse_players(CELL[user->y][user->x], user, utils))
    strcpy(str, "ok\n");
  else
    strcpy(str, "ko\n");
  return (str);
}
