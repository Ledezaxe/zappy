/*
** server_add_player.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Wed Jun 25 15:42:12 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 19:47:55 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include <string.h>
#include "server_add_player.h"
#include "t_user_list.h"
#include "error.h"
#include "server_user_inventory.h"
#include "t_players_ptr.h"
#include "server_time_controller.h"

int		add_player(t_utils *utils, int id, char *team, int egg)
{
  t_user_list	*player;

  if ((player = malloc(sizeof(t_user_list))) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  if ((init_player(utils->map, id, player, team)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((add_player_in_list(utils->user, player)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  put_player_in_cell(CELL[player->y][player->x]->pptr_list_desc, player);
  player->egg = egg;
  return (EXIT_SUCCESS);
}

int	init_player(t_map *map, int id, t_user_list *p, char *team)
{
  p->direction = rand() % 4;
  p->level = 1;
  p->team = team;
  p->id = id;
  p->life = 126;
  p->cursor = 0;
  p->x = rand() % map->width;
  p->y = rand() % map->height;
  clean_action_list(p);
  if ((p->inventory = malloc(sizeof(t_object))) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  reset_inventory(p->inventory);
  return (EXIT_SUCCESS);
}
