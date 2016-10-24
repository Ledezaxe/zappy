/*
** broadcast_ia.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Mon Jun 30 16:56:06 2014 stephane budelot
** Last update Sun Jul 13 14:39:36 2014 stephane budelot
*/

#include	<stdio.h>
#include	<stdarg.h>
#include	<stdlib.h>
#include	<string.h>

#include	"ia.h"
#include	"error.h"

int		broadcast_for_elevation(int fd, t_ia *ia)
{
  char		*buff;
  int		i;

  if ((buff = malloc(strlen("broadcast It's a call to prayer lvl: X\n")
		     + 1)) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  if (sprintf(buff, "broadcast It's a call to prayer lvl: %d\n", ia->lvl)
      == -1)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  i = send_serv(fd, buff);
  free(buff);
  return (i);
}

int		broadcast_here(int fd, t_ia *ia)
{
  ia->elev = 1;
  ia->broadcast_pos = -1;
  return (send_serv(fd, "broadcast I'm here for the elevation.\n"));
}

int		broadcast_elevation(int fd)
{
  return (send_serv(fd, "incantation\n"));
}

int		broadcast_elevation_end(int fd, t_ia *ia)
{
  char		*buff;
  int		i;

  if ((buff = malloc(sizeof(char) *
		     (strlen("broadcast Elevation end lvl: X\n") + 1))) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  if (sprintf(buff, "broadcast Elevation end lvl: %d\n", ia->lvl) == -1)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  i = send_serv(fd, buff);
  free(buff);
  return (i);
}

int		broadcast_cancel(int fd, t_ia *ia)
{
  char		*buff;
  int		i;

  if ((buff = malloc(sizeof(char) *
		     (strlen("broadcast Elevation cancel lvl: X\n") + 1))) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  if (sprintf(buff, "broadcast Elevation cancel lvl: %d\n", ia->lvl) == -1)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  i = send_serv(fd, buff);
  free(buff);
  return (i);
}
