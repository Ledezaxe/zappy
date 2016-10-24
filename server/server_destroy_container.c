/*
** server_destroy_container.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Tue Jun 24 18:14:53 2014 Nathan BIGAIGNON
** Last update Fri Jul 11 20:34:41 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "server_destroy_container.h"
#include "server_destroy_argument.h"
#include "server_destroy_map.h"
#include "server_destroy_socket.h"
#include "server_destroy_user_list.h"

void	destroy_container(t_utils *utils)
{
  destroy_argument(utils);
  destroy_monitor(utils->socket->monitors);
  destroy_socket(utils);
  destroy_map(utils);
  destroy_egg(utils->egg);
  destroy_user_list(utils);
}
