/*
** server_destroy_socket.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Tue Jun 24 18:34:56 2014 Nathan BIGAIGNON
** Last update Fri Jul 11 17:30:10 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "server_destroy_socket.h"

void	destroy_socket(t_utils *utils)
{
  free(SOCKET);
}
