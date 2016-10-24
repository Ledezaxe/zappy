/*
** server_destroy_user_list.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Wed Jun 25 13:35:31 2014 Nathan BIGAIGNON
** Last update Wed Jun 25 19:52:28 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "server_destroy_user_list.h"
#include "t_user_list.h"
#include "error.h"

void		destroy_user_list(t_utils *utils)
{
  t_user_list	*cursor;
  t_user_list	*tmp;

  cursor = utils->user->tail;
  while (cursor != NULL)
    {
      tmp = cursor;
      cursor = cursor->next;
      free(tmp->inventory);
      free(tmp);
    }
  free(utils->user);
}
