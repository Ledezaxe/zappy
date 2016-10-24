/*
** server_command_watch_down.c for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Sat Jun 28 12:51:07 2014 Max Prudhomme
** Last update Fri Jul 11 15:22:21 2014 Max Prudhomme
*/

#include "error.h"
#include "server_command_watch.h"
#include "server_command_watch_down.h"

int		s_look_down(t_user_list *us, t_utils *utils, t_uint *size)
{
  int		i;
  int		x;
  int		max;
  t_uint	lvl;
  int		y;

  lvl = 0;
  y = us->y;
  while (lvl <= us->level)
    {
      i = 0;
      x = RIGHT_CELL(us->x, lvl);
      max = (lvl * 2) + 1;
      while (i < max)
	{
	  if (size_append_cell_content(CELL[y][x], size, us) == -1)
	    return (-1);
	  x = LEFT_CELL(x, 1);
	  ++i;
	}
      ++lvl;
      y = BOTTOM_CELL(y, 1);
    }
  return (0);
}

int		look_down(t_user_list *user, t_utils *utils, char *str)
{
  int		i;
  int		x;
  int		max;
  t_uint	lvl;
  int		y;

  lvl = 0;
  y = user->y;
  while (lvl <= user->level)
    {
      i = 0;
      x = RIGHT_CELL(user->x, lvl);
      max = (lvl * 2) + 1;
      while (i < max)
	{
	  if (append_cell_content(CELL[y][x], str, user) == -1)
	    return (-1);
	  x = LEFT_CELL(x, 1);
	  ++i;
	}
      ++lvl;
      y = BOTTOM_CELL(y, 1);
    }
  return (0);
}
