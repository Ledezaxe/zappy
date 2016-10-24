/*
** server_stdin_monitoring.c for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Sat Jul 12 18:50:25 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 21:19:01 2014 Nathan BIGAIGNON
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "server_stdin_monitoring.h"
#include "server_loop.h"
#include "server_send_msg.h"
#include "error.h"

int	stdin_monitoring(t_utils *utils)
{
  char	str[255];
  int	bytes;

  memset(str, 0, 255);
  if ((bytes = read(STDIN, str, 255)) == -1)
    return (std_raise_error(__FUNCTION__, -QUIT));
  if (strcmp(str, "/quit\n") == 0)
    {
      printf("\033[1;31mThe server is shutting down.\033[0m\n");
      return (QUIT);
    }
  else
    broadcast_msg_to_monitors(utils, str);
  return (-QUIT);
}

void	broadcast_msg_to_monitors(t_utils *utils, char *str)
{
  char	tmp[270];

  memset(tmp, 0, 270);
  sprintf(tmp, "smg %s", str);
  send_msg_to_monitors(utils, tmp);
}
