/*
** tri_braodcast.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Sun Jul  6 12:38:38 2014 stephane budelot
** Last update Sun Jul 13 13:11:47 2014 stephane budelot
*/

#include	<stdlib.h>
#include	<string.h>

#include	"ia.h"
#include	"error.h"

static void	which_broadcast2(t_ia *ia)
{
  char		*lvl;

  if ((lvl = strstr(ia->broadcast, "Elevation end lvl: ")) != NULL ||
      (lvl = strstr(ia->broadcast, "Elevation cancel lvl: ")) != NULL)
    {
      if (ia->lvl == (0 < atoi(&lvl[19])) ? atoi(&lvl[19]) : atoi(&lvl[22]))
	{
	  ia->broadcast_pos = -1;
	  ia->elev = 0;
	  ia->nbr_here = 0;
	}
    }
  else if ((lvl = strstr(ia->broadcast, "Enough people for elevation lvl: "))
	   != NULL)
    if (ia->lvl == atoi(&lvl[33]))
      ia->broadcast_pos = -1;
}

static void	which_broadcast(t_ia *ia, int pos)
{
  char		*lvl;

  if ((lvl = strstr(ia->broadcast, "It's a call to prayer lvl:")) != NULL)
    {
      if (ia->lvl != atoi(&lvl[27]))
	ia->broadcast_pos = -1;
      else
	ia->broadcast_pos = pos;
    }
  else if ((lvl = strstr(ia->broadcast, "I'm here for the elevation.")) != NULL)
    {
      ia->broadcast_pos = pos;
      if (ia->broadcast_pos == 0)
	ia->nbr_here += 1;
    }
  else
    which_broadcast2(ia);
}

void		broadcast_txt(t_ia *ia, char *str)
{
  int		i;
  int		j;
  char		*pos;

  i = 0;
  j = 0;
  if ((pos = strstr(str, "message ")) != NULL)
    if (str[8] >= '0' && str[8] <= '9')
      if (str[9] == ',')
	{
	  i = 10;
	  j = 0;
	  memset(ia->broadcast, 0, 50);
	  while (str[i])
	    ia->broadcast[j++] = str[i++];
	  which_broadcast(ia, atoi(&pos[8]));
	}
}
