/*
** server_command_connect_nbr.c for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Thu Jul 10 15:34:42 2014 Nathan BIGAIGNON
** Last update Sat Jul 12 17:13:12 2014 Nathan BIGAIGNON
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server_commands_client.h"
#include "server_clients_controller.h"

char	*cmd_connect_nbr(t_user_list *user, t_utils *utils)
{
  char	*str;
  int	i;

  if ((i = check_team_name(utils, user->team)) == -1)
    return (NULL);
  if ((str = malloc(sizeof(char) * 255)) == NULL)
    {
      perror(__FUNCTION__);
      return (NULL);
    }
  memset(str, 0, 255);
  sprintf(str, "%d\n", (SOCKET->backlog / utils->args->nb_team)
	  - utils->args->player_in_team[i]);
  return (str);
}

