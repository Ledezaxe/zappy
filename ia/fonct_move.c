/*
** fonct_move.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Fri Jul  4 10:48:41 2014 stephane budelot
** Last update Fri Jul 11 16:40:31 2014 stephane budelot
*/

#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<stdarg.h>

#include	"ia.h"
#include	"error.h"

int		move_right(int fd)
{
  printf("droite\n");
  return (send_serv(fd, "droite\n"));
}

int		move_left(int fd)
{
  printf("gauche\n");
  return (send_serv(fd, "gauche\n"));
}

int		move_front(int fd)
{
  printf("avance\n");
  return (send_serv(fd, "avance\n"));
}

int		move_take(int i, int fd, t_ia *ia)
{
  char		buff[25];

  take_that_stone(g_type[i].name, ia);
  if (sprintf(buff, "prend %s\n", g_type[i].name) == -1)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  if (send_serv(fd, buff) == -1)
    return (-1);
  return (0);
}

int		move_pose(int i, int fd)
{
  char		buff[25];

  if (sprintf(buff, "pose %s\n", g_type[i].name) == -1)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  if (send_serv(fd, buff) == -1)
    return (-1);
  return (0);
}
