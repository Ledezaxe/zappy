/*
** server_destroy_egg_player.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Sun Jul 13 11:57:49 2014 Max Prudhomme
** Last update Sun Jul 13 19:12:50 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "server_destroy_egg_player.h"

void	delete_egg_player(t_utils *utils, t_user_list *user)
{
  t_user_list	*tmp;

  tmp = utils->user->tail;
  remove_player_in_cell(CELL[user->y][user->x]->pptr_list_desc, user);
  if (tmp == user)
    free_egg_player_unique_elem(tmp, utils);
  else
    free_egg_player_replace_ptr(tmp, utils, user);
  free(user->inventory);
  free(user);
}

void	free_egg_player_unique_elem(t_user_list *tmp, t_utils *utils)
{
  if (tmp == utils->user->head)
    {
      utils->user->tail = NULL;
      utils->user->head = NULL;
    }
  else
    utils->user->tail = tmp->next;
}

void	free_egg_player_replace_ptr(t_user_list *tmp, t_utils *utils,
				    t_user_list *user)
{
  while (tmp != NULL)
    {
      if (tmp->next == user)
	    {
	      if (tmp->next == utils->user->head)
		{
		  utils->user->head = tmp;
		  tmp->next = NULL;
		}
	      else
		tmp->next = tmp->next->next;
	    }
	  tmp = tmp->next;
    }
}
