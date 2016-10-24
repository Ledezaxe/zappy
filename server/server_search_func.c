/*
** server_search_func.c for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Sun Jul  6 12:09:02 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 19:15:51 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "server_search_func.h"
#include "t_monitors.h"
#include "t_user_list.h"

t_user_list	*get_user_from_id(t_utils *utils, int socket)
{
  t_user_list	*tmp;

  tmp = utils->user->tail;
  while (tmp != NULL)
    {
      if (tmp->id == (t_uint)socket && tmp->egg == 0)
	  return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

t_user_list	*get_egg_from_id(t_utils *utils, int socket)
{
  t_user_list	*tmp;

  tmp = utils->user->tail;
  while (tmp != NULL)
    {
      if (tmp->id == (t_uint)socket && tmp->egg == 1)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

int		is_monitor(t_monitors_desc *desc, int socket)
{
  t_monitors	*elem;

  elem = desc->tail;
  while (elem != NULL)
    {
      if (elem->id == socket)
	return (socket);
      elem = elem->next;
    }
  return (0);
}

int		is_ia(t_user_desc *desc, int socket)
{
  t_user_list	*tmp;

  tmp = desc->tail;
  while (tmp != NULL)
    {
      if (tmp->id == (t_uint)socket)
	return (socket);
      tmp = tmp->next;
    }
  return (0);
}

int	get_direction(unsigned char direction)
{
  if (direction == TOP)
    return (1);
  if (direction == DOWN)
    return (3);
  if (direction == LEFT)
    return (4);
  return (2);
}
