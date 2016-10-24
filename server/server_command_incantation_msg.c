/*
** server_command_incantation_msg.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Wed Jul  9 15:03:01 2014 Max Prudhomme
** Last update Fri Jul 11 15:29:22 2014 Max Prudhomme
*/

#include <stdio.h>
#include <string.h>
#include "server_command_incantation.h"
#include "server_send_msg.h"

void		send_incantation_msg(t_utils *utils, t_user_list *user)
{
  char		str[255];
  t_ptr_players	*player;

  memset(str, 0, 255);
  sprintf(str, "pic %d %d %d %d", user->x, user->y, user->level, user->id);
  player = CELL[user->y][user->x]->pptr_list_desc->tail;
  while (player != NULL)
    {
      sprintf(str, "%s %d", str, player->addr->level);
      player = player->next;
    }
  strcat(str, "\n");
  send_msg_to_monitors(utils, str);
}

void	send_incantation_finish(t_utils *utils, t_user_list *user, int lvl)
{
  char	str[255];

  memset(str, 0, 255);
  if (user->level == lvl)
    sprintf(str, "pie %d %d 1\n", user->x, user->y);
  else
    sprintf(str, "pie %d %d 0\n", user->x, user->y);
  send_msg_to_monitors(utils, str);
}
