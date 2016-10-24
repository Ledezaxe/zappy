/*
** search_rock.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Sun Jul  6 15:49:50 2014 stephane budelot
** Last update Fri Jul 11 19:42:32 2014 stephane budelot
*/

#include	<string.h>

#include	"ia.h"

void		take_that_stone(char *stone, t_ia *ia)
{
  if (strstr(stone, "linemate") != NULL)
    ia->tt_linemate += 1;
  else if (strstr(stone, "deraumere") != NULL)
    ia->tt_deraumere += 1;
  else if (strstr(stone, "sibur") != NULL)
    ia->tt_sibur += 1;
  else if (strstr(stone, "mendiane") != NULL)
    ia->tt_mendiane += 1;
  else if (strstr(stone, "phiras") != NULL)
    ia->tt_phiras += 1;
  else if (strstr(stone, "thystame") != NULL)
    ia->tt_thystame += 1;
}

void		pose_that_stone(char *stone, t_ia *ia)
{
  if (strstr(stone, "linemate") != NULL)
    ia->tt_linemate -= 1;
  else if (strstr(stone, "deraumere") != NULL)
    ia->tt_deraumere -= 1;
  else if (strstr(stone, "sibur") != NULL)
    ia->tt_sibur -= 1;
  else if (strstr(stone, "mendiane") != NULL)
    ia->tt_mendiane -= 1;
  else if (strstr(stone, "phiras") != NULL)
    ia->tt_phiras -= 1;
  else if (strstr(stone, "thystame") != NULL)
    ia->tt_thystame -= 1;
}

int		all_stone(t_ia *ia)
{
  int		allstone;
  int		i;

  if (ia->lvl != 8)
    {
      i = 0;
      while ((ia->lvl + 1) != g_stone[i].lvl)
	i++;
      if (ia->tt_linemate >= g_stone[i].lin &&
	  ia->tt_deraumere >= g_stone[i].der &&
	  ia->tt_sibur >= g_stone[i].sib &&
	  ia->tt_mendiane >= g_stone[i].men &&
	  ia->tt_phiras >= g_stone[i].phi &&
	  ia->tt_thystame >= g_stone[i].thy)
	  allstone = 1;
      else
	allstone = 0;
      return (allstone);
    }
  return (0);
}

int		search_stone(t_ia *ia)
{
  int		i;

  i = 0;
  while ((ia->lvl + 1) != g_stone[i].lvl)
    ++i;
  if (ia->tt_linemate < g_stone[i].lin)
    i = move_to_evolve(ia, g_type[1].type);
  else if (ia->tt_deraumere <  g_stone[i].der)
    i = move_to_evolve(ia, g_type[2].type);
  else if (ia->tt_sibur < g_stone[i].sib)
    i = move_to_evolve(ia, g_type[3].type);
  else if (ia->tt_mendiane < g_stone[i].men)
    i = move_to_evolve(ia, g_type[4].type);
  else if (ia->tt_phiras < g_stone[i].phi)
    i = move_to_evolve(ia, g_type[5].type);
  else if (ia->tt_thystame < g_stone[i].thy)
    i = move_to_evolve(ia, g_type[6].type);
  return (i);
}
