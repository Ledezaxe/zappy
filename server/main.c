/*
** main.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Tue Jun 24 14:07:22 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 21:23:44 2014 Nathan BIGAIGNON
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "server_check_args.h"
#include "t_server_options.h"
#include "t_utils.h"
#include "server_init_container.h"
#include "server_destroy_container.h"
#include "server_add_player.h"
#include "t_user_list.h"
#include "server_user_inventory.h"
#include "server_command_watch.h"
#include "server_init_socket.h"
#include "server_conf_socket.h"
#include "server_loop.h"
#include "server_random_resources.h"
#include "error.h"

int			main(int ac, char **av)
{
  t_server_options	options;
  t_utils		utils;

  printf("\033[1;34mServer loading...\033[0m\n");
  srand(time(NULL));
  if (start_checking(ac, av, &options) == -1)
    return (EXIT_FAILURE);
  if ((init_container(&utils, &options)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((utils.socket->listener = create_socket()) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((socket_name(&utils)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((conf_listener(&utils)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  gen_rand_resource(&utils);
  printf("\033[1;34m[Usage: /quit for exiting properly.]\033[0m\n");
  printf("\033[1;32mThe server is ready.\033[0m\n");
  if ((server_loop(&utils)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  close(utils.socket->listener);
  destroy_container(&utils);
  return (EXIT_SUCCESS);
}
