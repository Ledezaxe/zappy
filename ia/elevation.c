/*
** elevation.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Sun Jul  6 16:03:26 2014 stephane budelot
** Last update Sun Jul 13 11:09:34 2014 stephane budelot
*/

#include	"ia.h"

static int	move_to_elevation2(t_ia *ia)
{
  if (ia->broadcast_pos == 5)
    {
      if (move_right(ia->fd) == -1)
	return (-1);
      if (move_right(ia->fd) == -1)
	return (-1);
      return (move_x(ia, 1));
    }
  else if (ia->broadcast_pos == 6)
    {
      if (move_right(ia->fd) == -1)
	return (-1);
      return (move_in_diag_to_take(ia, 0, 1));
    }
  else if (ia->broadcast_pos == 7)
    {
      if (move_right(ia->fd) == -1)
	return (-1);
      return (move_x(ia, 1));
    }
  else if (ia->broadcast_pos == 8)
    return (move_in_diag_to_take(ia, 0, 1));
  return (see_map(ia));
}

int		move_to_elevation(t_ia *ia)
{
  if (ia->broadcast_pos == 0)
    {
      if (broadcast_here(ia->fd, ia) == -1)
	return (-1);
      return (0);
    }
  else if (ia->broadcast_pos == 1)
    return (move_x(ia, 1));
  else if (ia->broadcast_pos == 2)
    return (move_in_diag_to_take(ia, 1, 1));
  else if (ia->broadcast_pos == 3)
    {
      if (move_left(ia->fd) == -1)
	return (-1);
      return (move_x(ia, 1));
    }
  else if (ia->broadcast_pos == 4)
    {
      if (move_left(ia->fd) == -1)
	return (-1);
      return (move_in_diag_to_take(ia, 0, 1));
    }
  else
    return (move_to_elevation2(ia));
}

int		take_all_stone(t_ia *ia)
{
  int		i;

  i = 0;
  while (i < 7)
    {
      if (ia->lvl8[0][i] > 0)
	{
	  if (move_take(i, ia->fd, ia) == -1)
	    return (-1);
	  if (see_map(ia))
	    return (-1);
	}
      if (ia->lvl8[0][i] == 0)
	++i;
    }
  return (0);
}

static int	pose_stone_to_up2(t_ia *ia, int i)
{
  int		j;

  j = 0;
  while (j != g_stone[i].men)
    if (move_pose(4, ia->fd) == -1)
      return (-1);
    else
      ++j;
  j = 0;
  while (j != g_stone[i].phi)
    if (move_pose(5, ia->fd) == -1)
      return (-1);
    else
      ++j;
  j = 0;
  while (j != g_stone[i].thy)
    if (move_pose(6, ia->fd) == -1)
      return (-1);
    else
      ++j;
  return (0);
}

int		pose_stone_to_up(t_ia *ia)
{
  int		i;
  int		j;

  i = 0;
  while ((ia->lvl + 1) != g_stone[i].lvl)
    i++;
  j = 0;
  while (j != g_stone[i].lin)
    if (move_pose(1, ia->fd) == -1)
      return (-1);
    else
      ++j;
  j = 0;
  while (j != g_stone[i].der)
    if (move_pose(2, ia->fd) == -1)
      return (-1);
    else
      ++j;
  j = 0;
  while (j != g_stone[i].sib)
    if (move_pose(3, ia->fd) == -1)
      return (-1);
    else
      ++j;
  return (pose_stone_to_up2(ia, i));
}
