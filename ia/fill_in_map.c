/*
** fill_in_map.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Sun Jul  6 16:17:11 2014 stephane budelot
** Last update Sun Jul 13 14:39:56 2014 stephane budelot
*/

#include	<string.h>

#include	"ia.h"
#include	"error.h"

int		check_square(t_ia *m, char *str, int i)
{
  int	y;

  y = 0;
  if (str != NULL)
    while (y < 8)
      {
	m->lvl8[i][g_type[y].type] = 0;
	if (str[0] != '\0')
	  if (strstr(str, g_type[y].name) != NULL)
	    m->lvl8[i][g_type[y].type] = 1;
	++y;
      }
  else
    return (-1);
  return (0);
}

int		cut_string(t_ia *ia, char *str)
{
  char		buff[255];
  int		i;
  int		y;
  int		z;

  i = 1;
  y = 0;
  z = 0;
  ia->cmd_v = 0;
  memset(buff, 0, 255);
  while (str[i] != '\n')
    {
      if (str[i] == ',' || str[i] == '}')
	{
	  if (check_square(ia, buff, z) == -1)
	    return (-1);
	  memset(buff, 0, 255);
	  y = 0;
	  ++z;
	}
      else
	buff[y++] = str[i];
      ++i;
    }
  return (0);
}
