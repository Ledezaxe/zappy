/*
** t_egg.c for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Fri Jul 11 18:43:32 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 19:13:17 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "t_egg.h"
#include "error.h"

int	init_egg_list(t_utils *utils)
{
  if ((utils->egg = malloc(sizeof(t_egg_desc))) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  utils->egg->tail = NULL;
  utils->egg->head = NULL;
  utils->egg->index = 1;
  return (EXIT_SUCCESS);
}

int		add_egg_in_list(t_egg_desc *desc, t_utils *utils)
{
  t_egg		*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  elem->x = rand() % utils->map->width;
  elem->y = rand() % utils->map->height;
  elem->direction = rand() % 4;
  elem->life = 600;
  elem->id = desc->index;
  desc->index += 1;
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

void		rm_egg_from_list(t_egg_desc *desc, t_egg *elem)
{
  t_egg		*tmp;

  tmp = desc->tail;
  if (tmp == elem)
    free_egg_unique_elem(tmp, desc);
  else
    free_egg_replace_ptr(tmp, elem, desc);
  free(elem);
}

void	free_egg_unique_elem(t_egg *tmp, t_egg_desc *desc)
{
  if (tmp == desc->head)
    {
      desc->head = NULL;
      desc->tail = NULL;
    }
  else
    desc->tail = tmp->next;
}

void	free_egg_replace_ptr(t_egg *tmp, t_egg *elem, t_egg_desc *desc)
{
  while (tmp != NULL)
    {
      if (tmp->next == elem)
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
