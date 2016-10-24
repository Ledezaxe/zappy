/*
** t_players_ptr.c for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Fri Jul 11 11:51:03 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 19:13:56 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "error.h"
#include "t_players_ptr.h"

int		put_player_in_cell(t_ptr_players_desc *desc, t_user_list *p)
{
  t_ptr_players	*ptr;

  if ((ptr = malloc(sizeof(*ptr))) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  ptr->addr = p;
  if (desc->head == NULL && desc->tail == NULL)
    {
      desc->head = ptr;
      desc->tail = ptr;
      ptr->next = NULL;
    }
  else
    {
      ptr->next = desc->tail;
      desc->tail = ptr;
    }
  return (EXIT_SUCCESS);
}

void		remove_player_in_cell(t_ptr_players_desc *desc, t_user_list *p)
{
  t_ptr_players	*tmp;
  t_ptr_players	*dup;

  tmp = desc->tail;
  while (tmp != NULL)
    {
      if (tmp->addr == p)
	dup = tmp;
      tmp = tmp->next;
    }
  tmp = desc->tail;
  if (tmp != NULL)
    {
      if (tmp->addr == p)
	free_player_ptr_unique_elem(tmp, desc);
      else
	free_player_ptr_replace_ptr(tmp, p, desc);
      free(dup);
    }
}

void	free_player_ptr_unique_elem(t_ptr_players *tmp, t_ptr_players_desc *d)
{
  if (tmp == d->head)
    {
      d->head = NULL;
      d->tail = NULL;
    }
  else
    d->tail = tmp->next;
}

void	free_player_ptr_replace_ptr(t_ptr_players *tmp, t_user_list *p,
				    t_ptr_players_desc *desc)
{
  while (tmp != NULL)
    {
      if (tmp->next->addr == p)
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
