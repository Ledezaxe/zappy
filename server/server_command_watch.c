/*
** server_command_watch.c for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Sat Jun 28 12:04:53 2014 Max Prudhomme
** Last update Fri Jul 11 20:06:01 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "server_command_watch.h"
#include "server_command_watch_size.h"
#include "server_command_watch_up.h"
#include "server_command_watch_down.h"
#include "server_command_watch_left.h"
#include "server_command_watch_right.h"

static struct s_direction	g_direction[4] =
  {
    {TOP, s_look_up, look_up},
    {DOWN, s_look_down, look_down},
    {LEFT, s_look_left, look_left},
    {RIGHT, s_look_right, look_right}
  };

struct s_type	g_type[9] =
  {
    {LINEMATE, " linemate", 9},
    {DERAUMERE, " deraumere", 10},
    {SIBUR, " sibur", 6},
    {MENDIANE, " mendiane", 9},
    {PHIRAS, " phiras", 7},
    {THYSTAME, " thystame", 9},
    {FOOD, " nourriture", 11},
    {EGG, " oeuf", 5},
    {PLAYER, " joueur", 7}
  };

char		*cmd_watch(t_user_list *user, t_utils *utils)
{
  char		*str;
  t_uint	size_alloc;
  unsigned char	i;

  str = NULL;
  i = 0;
  while (i != user->direction)
    ++i;
  size_alloc = 2;
  if (g_direction[i].s_a(user, utils, &size_alloc) == -1)
    return (NULL);
  if ((str = malloc(sizeof(char) * size_alloc + 1)) == NULL)
    {
      std_raise_error(__FUNCTION__, -1);
      return (NULL);
    }
  memset(str, 0, size_alloc);
  strcpy(str, "{");
  if (g_direction[i].string(user, utils, str) == -1)
    return (NULL);
  str[strlen(str) - 1] = '}';
  str[strlen(str)] = '\n';
  return (str);
}

int		append_cell_content(t_cell *cell, char *str, t_user_list *user)
{
  if (append_cell_object(cell, str) == -1)
    return (-1);
  if (append_cell_player(cell, str, user) == -1)
    return (-1);
  strcat(str, ",");
  if (str == NULL)
    return (std_raise_error(__FUNCTION__, -1));
  return (0);
}

int	append_cell_object(t_cell *cell, char *str)
{
  if (cell->object->linemate != 0)
    if (append_element(LINEMATE, str, cell->object->linemate) == -1)
      return (-1);
  if (cell->object->deraumere != 0)
    if (append_element(DERAUMERE, str, cell->object->deraumere) == -1)
      return (-1);
  if (cell->object->sibur != 0)
    if (append_element(SIBUR, str, cell->object->sibur) == -1)
      return (-1);
  if (cell->object->mendiane != 0)
    if (append_element(MENDIANE, str, cell->object->mendiane) == -1)
      return (-1);
  if (cell->object->phiras != 0)
    if (append_element(PHIRAS, str, cell->object->phiras) == -1)
      return (-1);
  if (cell->object->thystame != 0)
    if (append_element(THYSTAME, str, cell->object->thystame) == -1)
      return (-1);
  if (cell->object->food != 0)
    if (append_element(FOOD, str, cell->object->food) == -1)
      return (-1);
  return (0);
}

int		append_element(unsigned char type, char *str, t_uint max)
{
  unsigned char	i;
  unsigned char	x;

  i = 0;
  while (g_type[i].type != type)
    ++i;
  x = 0;
  while (x < max)
    {
      strcat(str, g_type[i].str);
      if (str == NULL)
	return (std_raise_error(__FUNCTION__, -1));
      ++x;
    }
  return (0);
}

int		append_cell_player(t_cell *cell, char *str, t_user_list *user)
{
  t_ptr_players	*player;

  player = cell->pptr_list_desc->tail;
  while (player != NULL)
    {
      if (player->addr != user)
	append_element(PLAYER, str, 1);
      player = player->next;
    }
  return (0);
}
