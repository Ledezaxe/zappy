/*
** t_monitors.c for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Fri Jul 11 16:42:35 2014 Nathan BIGAIGNON
** Last update Sat Jul 12 17:17:59 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "t_monitors.h"
#include "error.h"

int		add_monitors_in_list(t_monitors_desc *desc, int socket)
{
  t_monitors	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  elem->id = socket;
  if (desc->head == NULL && desc->tail == NULL)
    {
      desc->head = elem;
      desc->tail = elem;
      elem->next = NULL;
    }
  else
    {
      elem->next = desc->tail;
      desc->tail = elem;
    }
  return (EXIT_SUCCESS);
}

void		rm_monitors_from_list(t_monitors_desc *desc, int socket)
{
  t_monitors	*tmp;
  t_monitors	*dup;

  tmp = desc->tail;
  while (tmp != NULL)
    {
      if (tmp->id == socket)
	dup = tmp;
      tmp = tmp->next;
    }
  tmp = desc->tail;
  if (tmp->id == socket)
    free_monitors_unique_elem(tmp, desc);
  else
    free_monitors_replace_ptr(tmp, socket, desc);
  free(dup);
}

void	free_monitors_unique_elem(t_monitors *tmp, t_monitors_desc *desc)
{
  if (tmp == desc->head)
    {
      desc->head = NULL;
      desc->tail = NULL;
    }
  else
    desc->tail = tmp->next;
}

void	free_monitors_replace_ptr(t_monitors *tmp, int socket,
				  t_monitors_desc *desc)
{
  while (tmp != NULL)
    {
      if (tmp->next->id == socket)
	{
	  if (tmp->next == desc->head)
	    {
	      desc->head = tmp;
	      tmp->next = NULL;
	    }
	  else
	    tmp->next = tmp->next->next;
	}
      tmp = tmp->next;
    }
}
