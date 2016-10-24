/*
** server_random_resources2.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Wed Jul  9 18:36:53 2014 Max Prudhomme
** Last update Wed Jul  9 18:37:56 2014 Max Prudhomme
*/

#include <stdlib.h>
#include "server_random_resources.h"

void	rand_phiras(t_utils *utils)
{
  CELL[(rand() % utils->map->height)][(rand() % utils->map->width)]
    ->object->phiras += 1;
}

void	rand_thystame(t_utils *utils)
{
  CELL[(rand() % utils->map->height)][(rand() % utils->map->width)]
    ->object->thystame += 1;
}
