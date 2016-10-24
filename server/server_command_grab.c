/*
** server_command_grab.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Thu Jul  3 17:11:00 2014 Max Prudhomme
** Last update Fri Jul 11 20:04:39 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "server_commands_client.h"
#include "server_command_grab_drop.h"
#include "error.h"
#include "server_send_msg.h"
#include "t_monitors.h"

struct s_grab_drop	g_grab_drop[7] = {
  {LINEMATE, "linemate", grab_linemate, drop_linemate},
  {DERAUMERE, "deraumere", grab_deraumere, drop_deraumere},
  {SIBUR, "sibur", grab_sibur, drop_sibur},
  {MENDIANE, "mendiane", grab_mendiane, drop_mendiane},
  {PHIRAS, "phiras", grab_phiras, drop_phiras},
  {THYSTAME, "thystame", grab_thystame, drop_thystame},
  {FOOD, "nourriture", grab_food, drop_food}
};

char		*cmd_grab(t_user_list *user, t_utils *utils)
{
  int		i;
  char		*str;
  char		tmp[255];

  i = 0;
  while (strstr(&SOCKET->buffer[6], g_grab_drop[i].name) == NULL && i < 7)
    ++i;
  if (i == 7)
    return (NULL);
  if ((str = malloc(sizeof(char) * 3 + 1)) == NULL)
    {
      std_raise_error(__FUNCTION__, -1);
      return (NULL);
    }
  if (g_grab_drop[i].fct_grab(CELL[user->y][user->x]->object, user) == 1)
    {
      strcpy(str, "ok\n");
      sprintf(tmp, "pgt %d %d\n", user->id, ((i == 7) ? 0 : (i + 1)));
      send_msg_to_monitors(utils, tmp);
      send_objects_content(utils, user);
    }
  else
    strcpy(str, "ko\n");
  return (str);
}

int		send_objects_content(t_utils *utils, t_user_list *user)
{
  t_monitors	*tmp;

  tmp = SOCKET->monitors->tail;
  while (tmp != NULL)
    {
      memset(SOCKET->buffer, 0, 255);
      sprintf(SOCKET->buffer, "pin %d\n", user->id);
      cmd_gui_inventory_player(tmp->id, utils);
      memset(SOCKET->buffer, 0, 255);
      sprintf(SOCKET->buffer, "bct %d %d\n", user->x, user->y);
      cmd_gui_case_content(tmp->id, utils);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
