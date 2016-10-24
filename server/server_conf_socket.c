/*
** server_conf_socket.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Mon Jun 30 12:47:29 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 19:34:39 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include <unistd.h>
#include "t_socket.h"
#include "server_conf_socket.h"
#include "error.h"

int	socket_name(t_utils *utils)
{
  SOCKET->sin.sin_family = AF_INET;
  SOCKET->sin.sin_port = htons(SOCKET->port);
  SOCKET->sin.sin_addr.s_addr = INADDR_ANY;
  if ((bind(SOCKET->listener,
	    (const struct sockaddr *)&(SOCKET->sin),
	    sizeof(SOCKET->sin))) == -1)
    {
      close(SOCKET->listener);
      return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
    }
  return (EXIT_SUCCESS);
}

int	conf_listener(t_utils *utils)
{
  if ((listen(SOCKET->listener, 25)) == -1)
    {
      close(SOCKET->listener);
      return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
    }
  return (EXIT_SUCCESS);
}

int	connect_socket(t_socket *s)
{
  int	new;

  s->clen = sizeof(s->caddr);
  if ((new = accept(s->listener, (struct sockaddr *)&(s->caddr),
		    &(s->clen))) == -1)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  return (new);
}
