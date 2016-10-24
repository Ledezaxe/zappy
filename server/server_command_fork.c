/*
** server_command_fork.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Sat Jul 12 10:35:46 2014 Max Prudhomme
** Last update Sun Jul 13 22:27:04 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "server_command_fork.h"
#include "server_send_msg.h"
#include "server_clients_controller.h"
#include "t_egg.h"

char	*cmd_fork(t_user_list *user, t_utils *utils)
{
  char	str[255];

  if (add_egg_in_list(utils->egg, utils) == EXIT_FAILURE)
    return (NULL);
  utils->args->require_client_nb += 1;
  send_msg_to_client(user->id, "ok\n");
  memset(str, 0, 255);
  sprintf(str, "enw %d %d %d %d\n", utils->egg->tail->id, user->id,
	  user->x, user->y);
  send_msg_to_monitors(utils, str);
  return (NULL);
}

void	fork_msg_start(t_utils *utils, t_user_list *p)
{
  char	str[255];

  memset(str, 0, 255);
  sprintf(str, "pfk %d\n", p->id);
  send_msg_to_monitors(utils, str);
}
