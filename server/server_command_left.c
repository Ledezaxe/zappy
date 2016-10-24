/*
** server_command_left.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Thu Jul  3 10:55:02 2014 Max Prudhomme
** Last update Fri Jul 11 20:04:53 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "server_commands_client.h"
#include "server_command_broadcast.h"

char	*cmd_left(t_user_list *user, t_utils *utils)
{
  char	*str;

  (void)utils;
  if ((str = malloc(sizeof(char) * 3 + 1)) == NULL)
    {
      std_raise_error(__FUNCTION__, -1);
      return (NULL);
    }
  strcpy(str, "ok\n");
  if (user->direction == TOP)
    user->direction = LEFT;
  else if (user->direction == LEFT)
    user->direction = DOWN;
  else if (user->direction == DOWN)
    user->direction = RIGHT;
  else
    user->direction = TOP;
  send_player_expulse(utils, user);
  return (str);
}
