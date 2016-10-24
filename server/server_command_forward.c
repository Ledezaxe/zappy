/*
** server_command_forward.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Fri Jul  4 15:19:06 2014 Max Prudhomme
** Last update Sun Jul 13 19:38:30 2014 Nathan BIGAIGNON
*/

#include <string.h>
#include <stdlib.h>
#include "t_user_list.h"
#include "server_command_forward.h"
#include "server_command_broadcast.h"
#include "error.h"

static struct s_move_direction	g_move_direction[4] =
  {
    {TOP, move_up},
    {DOWN, move_down},
    {LEFT, move_left},
    {RIGHT, move_right}
  };

char	*cmd_forward(t_user_list *user, t_utils *utils)
{
  char	*str;

  if ((str = malloc(sizeof(char) * 3 + 1)) == NULL)
    {
      std_raise_error(__FUNCTION__, -1);
      return (NULL);
    }
  move_player(utils, user);
  strcpy(str, "ok\n");
  send_player_expulse(utils, user);
  return (str);
}

void	move_player(t_utils *utils, t_user_list *user)
{
  int	i;

  i = 0;
  while (g_move_direction[i].direction != user->direction)
    ++i;
  g_move_direction[i].fct_move(utils, user);
}
