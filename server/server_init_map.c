/*
** server_init_map.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Thu Jun 19 17:30:52 2014 Nathan BIGAIGNON
** Last update Fri Jul 11 15:36:39 2014 Max Prudhomme
*/

#include	<stdlib.h>
#include	"server_init_map.h"
#include	"t_map.h"
#include	"error.h"

int		init_map(t_utils *utils)
{
  if ((utils->map = malloc(sizeof(t_map))) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  return (EXIT_SUCCESS);
}

void		set_width(t_uint width, t_utils *utils)
{
  utils->map->width = width;
}

void		set_height(t_uint height, t_utils *utils)
{
  utils->map->height = height;
}

int		init_cell(t_utils *utils)
{
  t_uint	y;
  t_uint	x;

  y = 0;
  if ((CELL = malloc(sizeof(t_cell**) * utils->map->height + 1)) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  while (utils->map->height > y)
    {
      if ((CELL[y] = malloc(sizeof(t_cell*) * utils->map->width + 1)) == NULL)
	return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
      x = 0;
      while (utils->map->width > x)
	{
	  if ((CELL[y][x] = malloc(sizeof(t_cell))) == NULL)
	    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
	  ++x;
	}
      ++y;
    }
  return (EXIT_SUCCESS);
}
