/*
** server_destroy_argument.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Tue Jun 24 18:23:27 2014 Nathan BIGAIGNON
** Last update Fri Jul  4 14:39:19 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "server_destroy_argument.h"

void		destroy_argument(t_utils *utils)
{
  t_uint	i;

  i = 0;
  while (i < utils->args->nb_team)
    free(utils->args->team[i++]);
  free(utils->args->team);
  free(utils->args->player_in_team);
  free(utils->args);
}
