/*
** server_random_resources.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Wed Jul  9 18:14:45 2014 Max Prudhomme
** Last update Sun Jul 13 19:50:08 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "server_random_resources.h"

static struct s_rand_stone	g_rand_stone[6] =
  {
    {0, rand_linemate},
    {1, rand_deraumere},
    {2, rand_sibur},
    {3, rand_mendiane},
    {4, rand_phiras},
    {5, rand_thystame},
  };

void		gen_rand_resource(t_utils *utils)
{
  t_uint	x;
  t_uint	i;
  t_uint	r;

  r = (rand() % (utils->map->width + utils->map->height));
  i = 0;
  while (i < r)
    {
      CELL[(rand() % utils->map->height)][(rand() % utils->map->width)]
	->object->food += 1;
      x = rand() % 6;
      g_rand_stone[x].fct(utils);
      ++i;
    }
}

void	rand_linemate(t_utils *utils)
{
  CELL[(rand() % utils->map->height)][(rand() % utils->map->width)]
    ->object->linemate += 1;
}

void	rand_deraumere(t_utils *utils)
{
  CELL[(rand() % utils->map->height)][(rand() % utils->map->width)]
    ->object->deraumere += 1;
}

void	rand_sibur(t_utils *utils)
{
  CELL[(rand() % utils->map->height)][(rand() % utils->map->width)]
    ->object->sibur += 1;
}

void	rand_mendiane(t_utils *utils)
{
  CELL[(rand() % utils->map->height)][(rand() % utils->map->width)]
    ->object->mendiane += 1;
}
