/*
** server_time_manager.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Fri Jul 11 17:24:13 2014 Max Prudhomme
** Last update Sun Jul 13 12:53:20 2014 Max Prudhomme
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "server_loop.h"
#include "server_time_controller.h"
#include "server_clients_controller.h"
#include "server_error.h"
#include "server_random_resources.h"
#include "server_send_msg.h"

int		user_manage_time(t_utils *utils, t_user_list *user)
{
  user->life -= 1;
  if (user->life <= 0)
    {
      if (user->inventory->food > 0)
	user->inventory->food -= 1;
      if (user->inventory->food <= 0)
	{
	  if (user->egg == 0)
	    recv_error(utils, user->id);
	  else
	    egg_is_dead(utils, user);
	  user = NULL;
	  return (1);
	}
      else
	user->life = 126;
    }
  return (0);
}

int		manage_time(t_utils *utils)
{
  static int	i = 0;

  if (check_end_game(utils) == QUIT)
    return (QUIT);
  time_eggs_hatch(utils);
  if (i == 0 && utils->user->tail != NULL)
    {
      gen_rand_resource(utils);
      i = 630;
    }
  else
    --i;
  return (0);
}

int		check_end_game(t_utils *utils)
{
  int		*nb_lvl8;
  t_uint	i;

  if ((nb_lvl8 = malloc(sizeof(int) * utils->args->nb_team)) == NULL)
    return (1);
  i = 0;
  while (i < utils->args->nb_team)
    nb_lvl8[i++] = 0;
  count_players_lvl8(utils, nb_lvl8);
  i = 0;
  while (i < utils->args->nb_team)
    {
      if (nb_lvl8[i] >= 8)
	{
	  free(nb_lvl8);
	  return (quit_game(utils, utils->args->team[i]));
	}
      ++i;
    }
  free(nb_lvl8);
  return (0);
}

int	quit_game(t_utils *utils, char *team)
{
  char	str[255];

  memset(str, 0, 255);
  sprintf(str, "seg %s\n", team);
  send_msg_to_monitors(utils, str);
  return (QUIT);
}

void		count_players_lvl8(t_utils *utils, int *nb_lvl8)
{
  t_user_list	*player;

  player = utils->user->tail;
  while (player != NULL)
    {
      if (player->level == 8)
	{
	  nb_lvl8[check_team_name(utils, player->team)] += 1;
	}
      player = player->next;
    }
}
