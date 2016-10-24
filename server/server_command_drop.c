/*
** server_command_drop.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Fri Jul  4 13:56:17 2014 Max Prudhomme
** Last update Fri Jul 11 20:03:37 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server_commands_client.h"
#include "server_command_grab_drop.h"
#include "error.h"
#include "server_send_msg.h"

char		*cmd_drop(t_user_list *user, t_utils *utils)
{
  int		i;
  char		*str;
  char		tmp[255];

  i = 0;
  while (strstr(&SOCKET->buffer[5], g_grab_drop[i].name) == NULL && i < 7)
    ++i;
  if (i == 7)
    return (NULL);
  if ((str = malloc(sizeof(char) * 3 + 1)) == NULL)
    {
      std_raise_error(__FUNCTION__, -1);
      return (NULL);
    }
  if (g_grab_drop[i].fct_drop(CELL[user->y][user->x]->object, user) == 1)
    {
      strcpy(str, "ok\n");
      sprintf(tmp, "pdr %d %d\n", user->id, ((i == 7) ? 0 : (i + 1)));
      send_msg_to_monitors(utils, tmp);
      send_objects_content(utils, user);
    }
  else
    strcpy(str, "ko\n");
  return (str);
}
