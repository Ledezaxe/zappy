/*
** algo_move.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Thu Jul  3 14:43:06 2014 stephane budelot
** Last update Fri Jul 11 16:42:59 2014 stephane budelot
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"ia.h"
#include	"error.h"

int		move_x(t_ia *m, int i)
{
  int		x;

  x = 0;
  while (x != i)
    {
      if (move_front(m->fd) == -1)
	return (-1);
      ++x;
    }
  return (0);
}

int		move_in_diag_to_take(t_ia *m, int dg, int x)
{
  if (move_x(m, x) == -1)
    return (-1);
  if (dg == 1)
    {
      if (move_left(m->fd) == -1)
	return (-1);
    }
  else
    if (move_right(m->fd) == -1)
      return (-1);
  if (move_x(m, x) == -1)
    return (-1);
  return (0);
}

int		move_to_take(t_ia *m, int obj, int i, int x)
{
  if (move_x(m, x) == -1)
    return (-1);
  if (m->lvl8[i][obj] > 0)
    return (move_take(obj, m->fd, m));
  else if (m->lvl8[i - 1][obj] > 0 || m->lvl8[i + 1][obj] > 0)
    {
      if (m->lvl8[i - 1][obj] > 0)
	{
	  if (move_left(m->fd) == -1)
	    return (-1);
	}
      else
	if (move_right(m->fd) == -1)
	  return (-1);
    }
  if (move_front(m->fd) == -1)
    return (-1);
  return (move_take(obj, m->fd, m));
}

static int	move_to_evolve2(t_ia *m, int obj)
{
  if (m->lvl8[4][obj] > 0)
    {
      if (move_in_diag_to_take(m, 1, 2) == -1)
	return (-1);
      return (move_take(obj, m->fd, m));
    }
  else
    {
      if (move_in_diag_to_take(m, 1, 2) == -1)
	return (-1);
      return (move_take(obj, m->fd, m));
    }
}

int		move_to_evolve(t_ia *m, int obj)
{
  if (communication_ia(m) == -1)
    return (-1);
  if (m->lvl8[0][obj] > 0)
    return (move_take(obj, m->fd, m));
  else if (m->lvl8[2][obj] > 0 || m->lvl8[1][obj] > 0 || m->lvl8[3][obj] > 0)
    return (move_to_take(m, obj, 2, 1));
  else if (m->lvl8[6][obj] > 0 || m->lvl8[5][obj] > 0 || m->lvl8[7][obj] > 0)
    return (move_to_take(m, obj, 6, 2));
  else if (m->lvl8[12][obj] > 0 || m->lvl8[11][obj] > 0 || m->lvl8[13][obj] > 0)
    return (move_to_take(m, obj, 12, 3));
  else if (m->lvl8[4][obj] > 0 || m->lvl8[8][obj] > 0)
    {
      if (move_to_evolve2(m, obj) == -1)
	return (-1);
    }
  else
    if (move_x(m, 1) == -1)
      return (-1);
  return (0);
}
