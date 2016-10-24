/*
** survive.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Sun Jul  6 16:02:42 2014 stephane budelot
** Last update Sun Jul 13 11:05:23 2014 stephane budelot
*/

#include	<stdio.h>

#include	"ia.h"

int		survive(t_ia *ia)
{
  if (inventaire(ia) == -1)
    return (-1);
  if (see_map(ia) == -1)
    return (-1);
  ia->broadcast_pos = -1;
  printf("J'ai la dalle!\n");
  if (move_to_evolve(ia, g_type[0].type) == -1)
    return (-1);
  return (0);
}
