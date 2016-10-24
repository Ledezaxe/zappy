/*
** server_add_egg_player.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Sun Jul 13 12:22:49 2014 Max Prudhomme
** Last update Sun Jul 13 19:11:34 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server_add_egg_player.h"
#include "server_send_msg.h"
#include "server_clients_controller.h"
#include "t_egg.h"

int		has_egg(t_utils *utils)
{
  t_user_list	*tmp;

  tmp = utils->user->tail;
  while (tmp != NULL)
    {
      if (tmp->egg == 1)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

t_user_list	*get_first_free_egg(t_utils *utils)
{
  t_user_list	*tmp;

  tmp = utils->user->tail;
  while (tmp != NULL)
    {
      if (tmp->egg == 1)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

int		add_egg_player(t_utils *utils, int socket, char *buffer)
{
  int		i;
  char		str[255];
  t_user_list	*player;

  i = 0;
  buffer[strlen(buffer) - 1] = '\0';
  if ((i = check_team_name(utils, buffer)) == -1)
    return (EXIT_FAILURE);
  player = get_first_free_egg(utils);
  if (utils->args->player_in_team[i] >= utils->args->require_client_nb)
    return (EXIT_FAILURE);
  utils->args->player_in_team[i] += 1;
  player->team = utils->args->team[i];
  sprintf(str, "ebo %d\n", player->id);
  send_msg_to_monitors(utils, str);
  player->id = socket;
  player->egg = 0;
  return (EXIT_SUCCESS);
}
