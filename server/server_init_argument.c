/*
** server_init_argument.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Thu Jun 19 17:37:20 2014 Nathan BIGAIGNON
** Last update Tue Jun 24 15:46:05 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "server_init_argument.h"
#include "error.h"

int	init_argument(t_utils *utils)
{
  if ((utils->args = malloc(sizeof(t_args))) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  return (EXIT_SUCCESS);
}

void	set_team(char **team, t_utils *utils)
{
  utils->args->team = team;
}

void	set_require_client_nb(t_uint require_client_nb, t_utils *utils)
{
  utils->args->require_client_nb = require_client_nb;
}

void	set_time(t_uint time, t_utils *utils)
{
  utils->args->time = time;
}

void	set_nb_team(t_uint nb_team, t_utils *utils)
{
  utils->args->nb_team = nb_team;
}
