/*
** server_destroy_egg.c for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Fri Jul 11 20:29:34 2014 Nathan BIGAIGNON
** Last update Fri Jul 11 20:47:18 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "server_destroy_container.h"

void	destroy_egg(t_egg_desc *desc)
{
  t_egg *cursor;
  t_egg *tmp;

  cursor = desc->tail;
  while (cursor != NULL)
    {
      tmp = cursor;
      cursor = cursor->next;
      free(tmp);
    }
  free(desc);
}
