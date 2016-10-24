/*
** server_command_watch_size.c for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Sat Jun 28 13:00:00 2014 Max Prudhomme
** Last update Sat Jul 12 17:40:48 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "error.h"
#include "server_command_watch_size.h"
#include "server_command_watch.h"

int	size_append_cell_content(t_cell *c, t_uint *s, t_user_list *user)
{
  if (size_append_cell_object(c, s) == -1)
    return (-1);
  if (size_append_cell_player(c, s, user) == -1)
    return (-1);
  *s += 1;
  return (0);
}

int	size_append_cell_object(t_cell *cell, t_uint *s_a)
{
  if (cell->object->linemate != 0)
    if (size_append_element(LINEMATE, s_a, cell->object->linemate) == -1)
      return (-1);
  if (cell->object->deraumere != 0)
    if (size_append_element(DERAUMERE, s_a, cell->object->deraumere) == -1)
      return (-1);
  if (cell->object->sibur != 0)
    if (size_append_element(SIBUR, s_a, cell->object->sibur) == -1)
      return (-1);
  if (cell->object->mendiane != 0)
    if (size_append_element(MENDIANE, s_a, cell->object->mendiane) == -1)
      return (-1);
  if (cell->object->phiras != 0)
    if (size_append_element(PHIRAS, s_a, cell->object->phiras) == -1)
      return (-1);
  if (cell->object->thystame != 0)
    if (size_append_element(THYSTAME, s_a, cell->object->thystame) == -1)
      return (-1);
  if (cell->object->food != 0)
    if (size_append_element(FOOD, s_a, cell->object->food) == -1)
      return (-1);
  return (0);
}

int		size_append_element(unsigned char type, t_uint *size, t_uint max)
{
  unsigned char	i;
  unsigned char	x;

  i = 0;
  while (g_type[i].type != type)
    ++i;
  x = 0;
  while (x < max)
    {
      *size += g_type[i].size;
      ++x;
    }
  return (0);
}

int		size_append_cell_player(t_cell *c, t_uint *s, t_user_list *user)
{
  t_ptr_players	*player;

  player = c->pptr_list_desc->tail;
  while (player != NULL)
    {
      if (player->addr != user)
	{
	  size_append_element(PLAYER, s, 1);
	  return (0);
	}
      player = player->next;
    }
  return (0);
}
