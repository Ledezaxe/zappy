/*
** server_init_container.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Tue Jun 24 14:36:08 2014 Nathan BIGAIGNON
** Last update Fri Jul 11 20:44:56 2014 Nathan BIGAIGNON
*/

#include "server_init_container.h"
#include "server_init_map.h"
#include "server_init_object.h"
#include "server_init_socket.h"
#include "server_init_argument.h"
#include "server_init_user_list.h"
#include "t_egg.h"

int	init_container(t_utils *utils, t_server_options *options)
{
  if ((init_argument(utils)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  set_team(options->team_name, utils);
  set_require_client_nb(options->num_client, utils);
  set_time(options->time_exec, utils);
  set_nb_team(options->nb_team, utils);
  if ((init_map(utils)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  set_width(options->map_width, utils);
  set_height(options->map_height, utils);
  if ((init_cell(utils)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((init_object(utils)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((init_socket(utils)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  set_port(options->num_port, utils);
  if ((init_user_list(utils)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((init_egg_list(utils)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
