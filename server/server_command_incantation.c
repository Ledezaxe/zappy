/*
** server_command_incantation.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Fri Jul  4 17:28:13 2014 Max Prudhomme
** Last update Sat Jul 12 10:34:19 2014 Max Prudhomme
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "t_utils.h"
#include "t_user_list.h"
#include "error.h"
#include "server_command_incantation.h"
#include "server_send_msg.h"

struct s_lvl_up	g_lvl_up[7] =
  {
    {2, 1, 1, 0, 0, 0, 0, 0},
    {3, 2, 1, 1, 1, 0, 0, 0},
    {4, 2, 2, 0, 1, 0, 2, 0},
    {5, 4, 1, 1, 2, 0, 1, 0},
    {6, 4, 1, 2, 1, 3, 0, 0},
    {7, 6, 1, 2, 3, 0, 1, 0},
    {8, 6, 2, 2, 2, 2, 2, 1}
  };

char		*cmd_incantation(t_user_list *user, t_utils *utils)
{
  char		*str;
  t_uint	lvl;

  lvl = user->level;
  if ((str = malloc(sizeof(char) * 20 + 1)) == NULL)
    {
      std_raise_error(__FUNCTION__, -1);
      return (NULL);
    }
  evolve_players(utils, user);
  sprintf(str, "niveau actuel : %d\n", user->level);
  send_incantation_finish(utils, user, lvl);
  return (str);
}

int		evolve_players(t_utils *utils, t_user_list *user)
{
  int		nb;
  t_ptr_players	*player;

  nb = 0;
  player = CELL[user->y][user->x]->pptr_list_desc->tail;
  while (player != NULL)
    {
      if (player->addr->level == user->level)
	++nb;
      else
	--nb;
      player = player->next;
    }
  if (nb != g_lvl_up[user->level - 1].player)
    return (1);
  start_elevation(utils, user);
  return (0);
}

void	reset_stone(t_stone *stone)
{
  stone->linemate = 0;
  stone->deraumere = 0;
  stone->sibur = 0;
  stone->mendiane = 0;
  stone->phiras = 0;
  stone->thystame = 0;
}

int	send_evolve_msg(t_utils *utils, t_user_list *user)
{
  char	*str;

  (void)utils;
  if ((str = malloc(sizeof(char) * 20 + 1)) == NULL)
    return (std_raise_error(__FUNCTION__, -1));
  sprintf(str, "niveau actuel : %d\n", user->level);
  send_msg_to_client(user->id, str);
  free(str);
  return (0);
}

void		incantation_msg_start(t_utils *utils, t_user_list *p)
{
  t_ptr_players	*player;

  player = CELL[p->y][p->x]->pptr_list_desc->tail;
  while (player != NULL)
    {
      send_msg_to_client(player->addr->id, "elevation en cours\n");
      player = player->next;
    }
  send_incantation_msg(utils, p);
}
