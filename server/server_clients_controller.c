/*
** server_clients_controller.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Tue Jul  1 14:52:20 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 19:44:22 2014 Nathan BIGAIGNON
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server_add_player.h"
#include "server_clients_controller.h"
#include "server_commands_client.h"
#include "error.h"
#include "server_send_msg.h"
#include "server_search_func.h"
#include "server_time_controller.h"
#include "t_monitors.h"

int	add_monitor(t_utils *utils, int socket)
{
  if ((add_monitors_in_list(SOCKET->monitors, socket)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  cmd_gui_map_size(socket, utils);
  cmd_gui_get_time(socket, utils);
  cmd_gui_map_content(socket, utils);
  cmd_gui_team_name(socket, utils);
  return (EXIT_SUCCESS);
}

int		add_ia(t_utils *utils, int socket, char *buffer)
{
  int		i;
  char		str[255];
  t_user_list	*player;

  buffer[strlen(buffer) - 1] = '\0';
  if ((i = check_team_name(utils, buffer)) != -1)
    {
      if ((store_ia(utils, buffer, i, socket)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    return (EXIT_FAILURE);
  player = get_user_from_id(utils, socket);
  clean_action_list(player);
  memset(str, 0, 255);
  player->cursor = 0;
  sprintf(str, "pnw %d %d %d %d %d %s\n", socket, player->x,
	  player->y, get_direction(player->direction),
	  player->level, player->team);
  send_msg_to_monitors(utils, str);
  return (EXIT_SUCCESS);
}

int		check_team_name(t_utils *utils, char *team)
{
  t_uint	i;

  i = 0;
  while (i < utils->args->nb_team)
    {
      if (strcmp(utils->args->team[i], team) == 0)
	return (i);
      ++i;
    }
  return (-1);
}

int	store_ia(t_utils *utils, char *buffer, int i, int socket)
{
  char	msg[255];

  (void)buffer;
  if (utils->args->player_in_team[i] < utils->args->require_client_nb)
    {
      utils->args->player_in_team[i] += 1;
      if ((add_player(utils, socket, utils->args->team[i], 0)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      memset(msg, 0, 255);
      sprintf(msg, "%d\n", (SOCKET->backlog / utils->args->nb_team)
	      - utils->args->player_in_team[i]);
      if ((send(socket, msg, strlen(msg), 0)) == -1)
	return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
      memset(msg, 0, 255);
      sprintf(msg, "%d %d\n", utils->map->width, utils->map->height);
      if ((send(socket, msg, strlen(msg), 0)) == -1)
	return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
    }
  else
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
