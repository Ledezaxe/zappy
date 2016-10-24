/*
** server_command_forward_move.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Fri Jul  4 15:33:19 2014 Max Prudhomme
** Last update Fri Jul 11 15:24:54 2014 Max Prudhomme
*/

#include "server_command_forward.h"
#include "server_command_watch.h"
#include "t_players_ptr.h"

void		move_up(t_utils *utils, t_user_list *user)
{
  t_uint	x;
  t_uint	y;

  x = user->x;
  y = user->y;
  user->y = TOP_CELL(y, 1);
  remove_player_in_cell(CELL[y][x]->pptr_list_desc, user);
  put_player_in_cell(CELL[user->y][x]->pptr_list_desc, user);
}

void	move_down(t_utils *utils, t_user_list *user)
{
  t_uint	x;
  t_uint	y;

  x = user->x;
  y = user->y;
  user->y = BOTTOM_CELL(y, 1);
  remove_player_in_cell(CELL[y][x]->pptr_list_desc, user);
  put_player_in_cell(CELL[user->y][x]->pptr_list_desc, user);
}

void	move_left(t_utils *utils, t_user_list *user)
{
  t_uint	x;
  t_uint	y;

  x = user->x;
  y = user->y;
  user->x = LEFT_CELL(x, 1);
  remove_player_in_cell(CELL[y][x]->pptr_list_desc, user);
  put_player_in_cell(CELL[y][user->x]->pptr_list_desc, user);
}

void	move_right(t_utils *utils, t_user_list *user)
{
  t_uint	x;
  t_uint	y;

  x = user->x;
  y = user->y;
  user->x = RIGHT_CELL(x, 1);
  remove_player_in_cell(CELL[y][x]->pptr_list_desc, user);
  put_player_in_cell(CELL[y][user->x]->pptr_list_desc, user);
}
