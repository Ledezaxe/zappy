/*
** server_destroy_map.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Tue Jun 24 18:43:28 2014 Nathan BIGAIGNON
** Last update Fri Jul 11 20:27:58 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "server_destroy_map.h"

void	destroy_map(t_utils *utils)
{
  destroy_cell(utils);
  free(utils->map);
}

void		destroy_cell(t_utils *utils)
{
  t_uint	y;
  t_uint	x;

  y = 0;
  while (utils->map->height > y)
    {
      x = 0;
      while (utils->map->width > x)
	{
	  free(CELL[y][x]->object);
	  destroy_pptr_in_cell(CELL[y][x]->pptr_list_desc);
	  free(CELL[y][x]);
	  ++x;
	}
      free(CELL[y]);
      ++y;
    }
  free(CELL);
}

void		destroy_pptr_in_cell(t_ptr_players_desc *desc)
{
  t_ptr_players	*cursor;
  t_ptr_players	*tmp;

  cursor = desc->tail;
  while (cursor != NULL)
    {
      tmp = cursor;
      cursor = cursor->next;
      free(tmp);
    }
  free(desc);
}
