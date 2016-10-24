/*
** server_time_manager2.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Sat Jul 12 12:00:01 2014 Max Prudhomme
** Last update Sun Jul 13 19:15:18 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server_time_controller.h"
#include "server_send_msg.h"
#include "server_add_player.h"
#include "server_search_func.h"
#include "t_players_ptr.h"
#include "server_destroy_egg_player.h"

int		time_eggs_hatch(t_utils *utils)
{
  t_egg		*egg;
  t_egg		*dup;

  egg = utils->egg->tail;
  while (egg != NULL)
    {
      dup = egg->next;
      egg->life -= 1;
      if (egg->life <= 0)
	egg_is_hatching(utils, egg);
      egg = dup;
    }
  return (0);
}

void	egg_is_hatching(t_utils *utils, t_egg *egg)
{
  t_user_list	*p;

  add_player(utils, egg->id, NULL, 1);
  p = get_egg_from_id(utils, egg->id);
  remove_player_in_cell(CELL[p->y][p->x]->pptr_list_desc, p);
  p->x = egg->x;
  p->y = egg->y;
  p->direction = egg->direction;
  put_player_in_cell(CELL[p->y][p->x]->pptr_list_desc, p);
  delete_egg(utils, egg);
}

void	delete_egg(t_utils *utils, t_egg *egg)
{
  char	str[255];

  memset(str, 0, 255);
  sprintf(str, "eht %d\n", egg->id);
  send_msg_to_monitors(utils, str);
  rm_egg_from_list(utils->egg, egg);
}

void	egg_is_dead(t_utils *utils, t_user_list *user)
{
  char	str[255];

  memset(str, 0, 255);
  sprintf(str, "edi %d\n", user->id);
  send_msg_to_monitors(utils, str);
  delete_egg_player(utils, user);
}
