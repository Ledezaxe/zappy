/*
** server_destroy_monitor.c for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Fri Jul 11 19:27:19 2014 Nathan BIGAIGNON
** Last update Fri Jul 11 20:23:24 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "server_destroy_container.h"

void		destroy_monitor(t_monitors_desc *desc)
{
  t_monitors	*cursor;
  t_monitors	*tmp;

  cursor = desc->tail;
  while (cursor != NULL)
    {
      tmp = cursor;
      cursor = cursor->next;
      free(tmp);
    }
  free(desc);
}
