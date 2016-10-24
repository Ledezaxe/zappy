/*
** server_init_object.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Thu Jun 19 20:38:07 2014 Nathan BIGAIGNON
** Last update Fri Jul 11 15:12:18 2014 Max Prudhomme
*/

#include	<stdlib.h>
#include	"server_init_object.h"
#include	"t_map.h"
#include	"t_cell.h"
#include	"error.h"

int		init_object(t_utils *utils)
{
  t_uint	y;
  t_uint	x;

  y = 0;
  while (utils->map->height > y)
    {
      x = 0;
      while (utils->map->width > x)
	{
	  CELL[y][x]->object = NULL;
	  if ((CELL[y][x]->object = malloc(sizeof(t_object))) == NULL)
	    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
	  if ((CELL[y][x]->pptr_list_desc = malloc(sizeof(t_ptr_players_desc)))
	      == NULL)
	    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
	  CELL[y][x]->pptr_list_desc->head = NULL;
	  CELL[y][x]->pptr_list_desc->tail = NULL;
	  reset_object(CELL[y][x]->object);
	  ++x;
	}
      ++y;
    }
  return (EXIT_SUCCESS);
}

void	reset_object(t_object *object)
{
  object->linemate = 0;
  object->deraumere = 0;
  object->sibur = 0;
  object->mendiane = 0;
  object->phiras = 0;
  object->thystame = 0;
  object->food = 0;
  object->egg = 0;
}
