/*
** server_command_incantation_evolve.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Thu Jul 10 11:43:18 2014 Max Prudhomme
** Last update Fri Jul 11 15:31:25 2014 Max Prudhomme
*/

#include <stdlib.h>
#include "server_command_incantation.h"

static void	get_stone(t_utils *utils, t_user_list *user, t_stone *stone)
{
  stone->linemate = CELL[user->y][user->x]->object->linemate;
  stone->deraumere = CELL[user->y][user->x]->object->deraumere;
  stone->sibur = CELL[user->y][user->x]->object->sibur;
  stone->mendiane = CELL[user->y][user->x]->object->mendiane;
  stone->phiras = CELL[user->y][user->x]->object->phiras;
  stone->thystame = CELL[user->y][user->x]->object->thystame;
}

static void	delete_stone(t_utils *utils, t_user_list *user)
{
  t_ptr_players	*player;

  CELL[user->y][user->x]->object->linemate = 0;
  CELL[user->y][user->x]->object->deraumere = 0;
  CELL[user->y][user->x]->object->sibur = 0;
  CELL[user->y][user->x]->object->mendiane = 0;
  CELL[user->y][user->x]->object->phiras = 0;
  CELL[user->y][user->x]->object->thystame = 0;
  player = CELL[user->y][user->x]->pptr_list_desc->tail;
  while (player != NULL)
    {
      player->addr->level += 1;
      if (player->addr != user)
	send_evolve_msg(utils, player->addr);
      player = player->next;
    }
}

int		start_elevation(t_utils *utils, t_user_list *user)
{
  t_stone	stone;

  reset_stone(&stone);
  get_stone(utils, user, &stone);
  if ((stone.linemate == g_lvl_up[user->level - 1].linemate) &&
      (stone.deraumere == g_lvl_up[user->level - 1].deraumere) &&
      (stone.sibur == g_lvl_up[user->level - 1].sibur) &&
      (stone.mendiane == g_lvl_up[user->level - 1].mendiane) &&
      (stone.phiras == g_lvl_up[user->level - 1].phiras) &&
      (stone.thystame == g_lvl_up[user->level - 1].thystame))
    delete_stone(utils, user);
  return (0);
}
