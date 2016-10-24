/*
** server_command_watch_right.c for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Sat Jun 28 12:51:07 2014 Max Prudhomme
** Last update Fri Jul 11 15:23:18 2014 Max Prudhomme
*/

#include "error.h"
#include "server_command_watch.h"
#include "server_command_watch_right.h"

int		s_look_right(t_user_list *u, t_utils *utils, t_uint *size)
{
  int		i;
  int		x;
  int		max;
  t_uint	lvl;
  int		y;

  lvl = 0;
  x = u->x;
  while (lvl <= u->level)
    {
      i = 0;
      y = TOP_CELL(u->y, lvl);
      max = (lvl * 2) + 1;
      while (i < max)
	{
	  if (size_append_cell_content(CELL[y][x], size, u) == -1)
	    return (-1);
	  y = BOTTOM_CELL(y, 1);
	  ++i;
	}
      ++lvl;
      x = RIGHT_CELL(x, 1);
    }
  return (0);
}

int		look_right(t_user_list *user, t_utils *utils, char *str)
{
  int		i;
  int		x;
  int		max;
  t_uint	lvl;
  int		y;

  lvl = 0;
  x = user->x;
  while (lvl <= user->level)
    {
      i = 0;
      y = TOP_CELL(user->y, lvl);
      max = (lvl * 2) + 1;
      while (i < max)
	{
	  if (append_cell_content(CELL[y][x], str, user) == -1)
	    return (-1);
	  y = BOTTOM_CELL(y, 1);
	  ++i;
	}
      ++lvl;
      x = RIGHT_CELL(x, 1);
    }
  return (0);
}
