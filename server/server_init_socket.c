/*
** server_init_socket.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Thu Jun 19 16:01:55 2014 Nathan BIGAIGNON
** Last update Fri Jul 11 16:45:22 2014 Nathan BIGAIGNON
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "server_init_socket.h"
#include "error.h"

int	init_socket(t_utils *utils)
{
  int	backlog;
  int	i;

  backlog = (utils->args->require_client_nb) * (utils->args->nb_team);
  i = 0;
  if ((SOCKET = malloc(sizeof(t_socket))) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  if ((SOCKET->monitors = malloc(sizeof(t_monitors_desc))) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  SOCKET->monitors->tail = NULL;
  SOCKET->monitors->head = NULL;
  SOCKET->backlog = backlog;
  return (EXIT_SUCCESS);
}

void	set_port(t_uint port, t_utils *utils)
{
  SOCKET->port = port;
}

int	create_socket(void)
{
  int	listener;

  if ((listener = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  return (listener);
}
