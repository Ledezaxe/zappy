/*
** ia.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Wed Jun 25 15:00:05 2014 stephane budelot
** Last update Sun Jul 13 14:40:55 2014 stephane budelot
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"ia.h"

struct s_lvlup	g_stone[7] =
  {
    {2, 1, 0, 0, 0, 0, 0, 1},
    {3, 1, 1, 1, 0, 0, 0, 2},
    {4, 2, 0, 1, 0, 2, 0, 2},
    {5, 1, 1, 2, 0, 1, 0, 4},
    {6, 1, 2, 1, 3, 0, 0, 4},
    {7, 1, 2, 3, 0, 1, 0, 6},
    {8, 2, 2, 2, 2, 2, 1, 6}
  };

struct s_type	g_type[8] =
  {
    {"nourriture", 0},
    {"linemate", 1},
    {"deraumere", 2},
    {"sibur", 3},
    {"mendiane", 4},
    {"phiras", 5},
    {"thystame", 6},
    {"joueur", 7}
  };

int		start_elevation(t_ia *ia)
{
  if (take_all_stone(ia) == -1)
    return (-1);
  if (ia->lvl != 1 && ia->broadcast_pos == -1)
    while (ia->nbr_here < (g_stone[ia->lvl - 1].nbr_j - 1))
      {
	if (broadcast_for_elevation(ia->fd, ia) == -1)
	  return (-1);
	if (ia->life < (ia->lvl * 2))
	  {
	    if (broadcast_cancel(ia->fd, ia) == -1)
	      return (-1);
	    else
	      return (1);
	  }
	if (inventaire(ia) == -1)
	  return (-1);
      }
  if (broadcast_enough_people(ia->fd, ia) == -1)
    return (-1);
  if (pose_stone_to_up(ia) == -1)
    return (-1);
  if (broadcast_elevation(ia->fd) == -1)
    return (-1);
  return (0);
}

static int	routine_ia(t_ia *ia)
{
  if (ia->life <= (ia->lvl * 2))
    {
      while ((ia->life < (ia->lvl * 10)) && (ia->dead != 1))
	if (survive(ia) == -1)
	  return (-1);
      if (do_fork(ia) == -1)
	return (-1);
    }
  else if (ia->broadcast_pos != -1)
    {
      if (move_to_elevation(ia) == -1)
	return (-1);
    }
  else if ((ia->lvl < 8) && (all_stone(ia) == 1))
    {
      if (start_elevation(ia) == -1)
	return (-1);
    }
  else
    if (search_stone(ia) == -1)
      return (-1);
  return (0);
}

int		new_ia(int fd)
{
  t_ia		ia;

  init_ia(&ia);
  ia.fd = fd;
  while (ia.dead == 0)
    {
      if (inventaire(&ia) == -1)
	return (-1);
      if (see_map(&ia) == -1)
	return (-1);
      if (ia.dead == 0)
	if (routine_ia(&ia) == -1)
	  return (-1);
      while (ia.elev == 1)
	if (communication_ia(&ia) == -1)
	  return (-1);
    }
  return (0);
}
