/*
** server_commands_client.c for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Fri Jul  4 14:50:09 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 19:24:25 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "string.h"
#include "server_commands_client.h"
#include "server_clients_controller.h"
#include "server_send_msg.h"
#include "server_search_func.h"
#include "server_random_resources.h"
#include "server_time_controller.h"
#include "server_store_scheduled_cmd.h"
#include "server_add_egg_player.h"

struct s_command g_ia[12] = {
  {"avance", cmd_forward, 7},
  {"droite", cmd_right, 7},
  {"gauche", cmd_left, 7},
  {"voir", cmd_watch, 7},
  {"inventaire", cmd_inventory, 1},
  {"prend ", cmd_grab, 7},
  {"pose ", cmd_drop, 7},
  {"expulse\n", cmd_expulse, 7},
  {"broadcast ", cmd_broadcast, 7},
  {"fork\n", cmd_fork, 42},
  {"connect_nbr\n", cmd_connect_nbr, 0},
  {"incantation\n", cmd_incantation, 300}
};

static struct s_command_gui g_gui[9] = {
  {"msz\n", cmd_gui_map_size},
  {"bct ", cmd_gui_case_content},
  {"mct\n", cmd_gui_map_content},
  {"tna ", cmd_gui_team_name},
  {"ppo ", cmd_gui_pos_player},
  {"plv ", cmd_gui_lvl_player},
  {"pin ", cmd_gui_inventory_player},
  {"sgt\n", cmd_gui_get_time},
  {"sst ", cmd_gui_edit_time}
};

int	command_exists(char *str, char *cmd)
{
  char	*first_pos;

  first_pos = NULL;
  first_pos = strstr(str, cmd);
  if (first_pos == str)
    return (1);
  return (0);
}

int		input_controller(t_utils *utils, int socket)
{
  int		i;

  i = 0;
  if (strcmp(SOCKET->buffer, "GRAPHIC\n") == 0 &&
      get_user_from_id(utils, socket) == NULL &&
      is_monitor(SOCKET->monitors, socket) == 0)
    {
      return (add_monitor(utils, socket));
    }
  if (get_user_from_id(utils, socket) == NULL &&
      is_monitor(SOCKET->monitors, socket) == 0)
    {
      if (has_egg(utils) == 1)
	return (add_egg_player(utils, socket, SOCKET->buffer) ==
		EXIT_FAILURE ? EXIT_FAILURE : EXIT_SUCCESS);
      else if ((add_ia(utils, socket, SOCKET->buffer)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    {
      if ((command_dispatcher(SOCKET->buffer, utils, socket)) == EXIT_SUCCESS)
	return (EXIT_SUCCESS);
    }
  return (EXIT_SUCCESS);
}

int		exec_gui_command(char *cmd, t_utils *utils, int socket)
{
  int		i;

  i = 0;
  while (command_exists(cmd, g_gui[i].name) == 0 && i < 9 &&
	 is_monitor(SOCKET->monitors, socket))
    ++i;
  if (i < 9 && is_monitor(SOCKET->monitors, socket))
    {
      g_gui[i].fct(socket, utils);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int		exec_ia_command(char *cmd, t_utils *utils, int socket)
{
  int		i;
  t_user_list	*p;
  char		*str;
  int		index;

  i = 0;
  while (command_exists(cmd, g_ia[i].name) == 0 && i < 12 &&
	 !is_monitor(SOCKET->monitors, socket))
    ++i;
  if (i < 12 && !is_monitor(SOCKET->monitors, socket))
    {
      p = get_user_from_id(utils, socket);
      if (g_ia[i].time == 0)
	{
	  if ((str = g_ia[i].fct(p, utils)) == NULL)
	    return (EXIT_FAILURE);
	  send(p->id, str, strlen(str), 0);
	  free(str);
	  return (EXIT_SUCCESS);
	}
      if ((index = register_action(p)) != -1)
	store_scheduled_cmd(utils, p, index, i);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int		command_dispatcher(char *cmd, t_utils *utils, int socket)
{
  if (exec_gui_command(cmd, utils, socket) == EXIT_SUCCESS)
    return (EXIT_SUCCESS);
  if (exec_ia_command(cmd, utils, socket) == EXIT_SUCCESS)
    return (EXIT_SUCCESS);
  if (is_monitor(SOCKET->monitors, socket))
    send_msg_to_client(socket, "suc\n");
  else
    send_msg_to_client(socket, "ko\n");
  return (EXIT_FAILURE);
}
