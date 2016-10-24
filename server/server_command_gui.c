/*
** server_command_gui.c for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Sun Jul  6 15:29:52 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 20:06:15 2014 Nathan BIGAIGNON
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server_commands_client.h"
#include "server_send_msg.h"

char	*cmd_gui_map_size(int socket, t_utils *utils)
{
  char	str[255];

  memset(str, 0, 255);
  sprintf(str, "msz %d %d\n", utils->map->width, utils->map->height);
  if ((send(socket, str, strlen(str), 0)) == -1)
    return (NULL);
  return (NULL);
}

char	*cmd_gui_case_content(int socket, t_utils *utils)
{
  int	i;
  int	x;
  int	y;

  i = 5;
  x = 0;
  y = 0;
  x = atoi(&SOCKET->buffer[4]);
  x = (x > 0 && x < (int)utils->map->width) ? x : 0;
  while (SOCKET->buffer[i] != ' ' && SOCKET->buffer[i] != '\0')
    ++i;
  if (SOCKET->buffer[i] != '\0')
    y = atoi(&SOCKET->buffer[i + 1]);
  y = (y > 0 && y < (int)utils->map->height) ? y : 0;
  case_content(x, y, utils, socket);
  return (NULL);
}

void	case_content(int x, int y, t_utils *utils, int socket)
{
  char	str[255];

  memset(str, 0, 255);
  sprintf(str, "bct %d %d %d %d %d %d %d %d %d\n", x,
	  y, CELL[y][x]->object->food,
	  CELL[y][x]->object->linemate, CELL[y][x]->object->deraumere,
	  CELL[y][x]->object->sibur, CELL[y][x]->object->mendiane,
	  CELL[y][x]->object->phiras, CELL[y][x]->object->thystame);
  send(socket, str, strlen(str), 0);
}

char		*cmd_gui_map_content(int socket, t_utils *utils)
{
  t_uint	y;
  t_uint	x;

  y = 0;
  while (y < utils->map->height)
    {
      x = 0;
      while (x < utils->map->width)
	{
	  case_content(x, y, utils, socket);
	  ++x;
	}
      ++y;
    }
  return (NULL);
}

char		*cmd_gui_team_name(int socket, t_utils *utils)
{
  t_uint	i;
  char		str[255];

  i = 0;
  (void)socket;
  while (i < utils->args->nb_team)
    {
      memset(str, 0, 255);
      sprintf(str, "tna %s\n", utils->args->team[i]);
      send(socket, str, strlen(str), 0);
      ++i;
    }
  return (NULL);
}
