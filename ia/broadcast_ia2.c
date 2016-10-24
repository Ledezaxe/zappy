/*
** broadcast_ia2.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Sun Jul 13 12:56:47 2014 stephane budelot
** Last update Sun Jul 13 14:43:02 2014 stephane budelot
*/

#include	<stdio.h>
#include	<stdarg.h>
#include	<stdlib.h>
#include	<string.h>

#include	"ia.h"
#include	"error.h"

int		broadcast_enough_people(int fd, t_ia *ia)
{
  char		*buff;
  int		i;

  i = strlen("broadcast Enough people for elevation lvl: X\n");
  if ((buff = malloc(sizeof(char) * (i) + 1)) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  if (sprintf(buff, "broadcast Enough people for elevation lvl: %d\n",
	      ia->lvl) == -1)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  i = send_serv(fd, buff);
  free(buff);
  return (i);
}
