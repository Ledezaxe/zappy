/*
** server_send_msg.c<2> for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Sat Jul  5 20:16:49 2014 Nathan BIGAIGNON
** Last update Fri Jul 11 17:23:57 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "string.h"
#include "server_send_msg.h"
#include "error.h"
#include "t_monitors.h"

int		send_msg_to_monitors(t_utils *utils, char *msg)
{
  t_monitors	*tmp;

  tmp = SOCKET->monitors->tail;
  while (tmp != NULL)
    {
      if ((send(tmp->id, msg, strlen(msg), 0)) == -1)
	return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int	send_msg_to_client(int socket, char *msg)
{
  if ((send(socket, msg, strlen(msg), 0)) == -1)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  return (EXIT_SUCCESS);
}
