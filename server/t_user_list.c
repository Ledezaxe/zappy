/*
** t_user_list.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Thu Jun 19 18:13:12 2014 Nathan BIGAIGNON
** Last update Sat Jul 12 19:15:06 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "t_user_list.h"

int	add_player_in_list(t_user_desc *desc, t_user_list *player)
{
  if (desc->head == NULL)
    {
      desc->head = player;
      desc->tail = player;
      desc->size += 1;
      player->next = NULL;
    }
  else
    {
      player->next = desc->tail;
      desc->tail = player;
      desc->size += 1;
    }
  return (0);
}
