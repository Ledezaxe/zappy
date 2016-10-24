/*
** server_command_gui2.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Sun Jul  6 16:28:27 2014 Max Prudhomme
** Last update Thu Jul 10 18:27:31 2014 Max Prudhomme
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server_commands_client.h"
#include "server_send_msg.h"
#include "server_search_func.h"

char	*cmd_gui_edit_time(int socket, t_utils *utils)
{
  int	t;

  t = atoi(&SOCKET->buffer[4]);
  if (t <= 0)
    {
      send_msg_to_monitors(utils, "sbp\n");
      return (NULL);
    }
  utils->args->time = (t < 1000000 ? ((t_uint)t) : 100);
  cmd_gui_get_time(socket, utils);
  return (NULL);
}

char	*cmd_gui_get_time(int socket, t_utils *utils)
{
  char	str[255];

  memset(str, 0, 255);
  sprintf(str, "sgt %d\n", utils->args->time);
  if ((send(socket, str, strlen(str), 0)) == -1)
    return (NULL);
  return (NULL);
}

char		*cmd_gui_inventory_player(int socket, t_utils *utils)
{
  char		str[255];
  int		u;
  t_user_list	*p;

  memset(str, 0, 255);
  u = atoi(&SOCKET->buffer[4]);
  p = get_user_from_id(utils, u);
  if (p == NULL)
    {
      send_msg_to_monitors(utils, "sbp\n");
      return (NULL);
    }
  sprintf(str, "pin %d %d %d %d %d %d %d %d %d %d\n", p->id, p->x, p->y,
	  p->inventory->food, p->inventory->linemate, p->inventory->deraumere,
	  p->inventory->sibur, p->inventory->mendiane, p->inventory->phiras,
	  p->inventory->thystame);
  if ((send(socket, str, strlen(str), 0)) == -1)
    return (NULL);
  return (NULL);
}

char		*cmd_gui_lvl_player(int socket, t_utils *utils)
{
  char		str[255];
  int		u;
  t_user_list	*p;

  memset(str, 0, 255);
  u = atoi(&SOCKET->buffer[4]);
  p = get_user_from_id(utils, u);
  if (p == NULL)
    {
      send_msg_to_monitors(utils, "sbp\n");
      return (NULL);
    }
  sprintf(str, "plv %d %d\n", p->id, p->level);
  if ((send(socket, str, strlen(str), 0)) == -1)
    return (NULL);
  return (NULL);
}

char		*cmd_gui_pos_player(int socket, t_utils *utils)
{
  char		str[255];
  int		u;
  int		d;
  t_user_list	*p;

  memset(str, 0, 255);
  u = atoi(&SOCKET->buffer[4]);
  p = get_user_from_id(utils, u);
  if (p == NULL)
    {
      send_msg_to_monitors(utils, "sbp\n");
      return (NULL);
    }
  if (p->direction == TOP)
    d = 1;
  else if (p->direction == DOWN)
    d = 3;
  else
    d = (p->direction == LEFT) ? 4 : 2;
  sprintf(str, "ppo %d %d %d %d\n", p->id, p->x, p->y, d);
  if ((send(socket, str, strlen(str), 0)) == -1)
    return (NULL);
  return (NULL);
}
