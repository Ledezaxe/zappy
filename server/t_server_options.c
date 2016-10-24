/*
** t_server_options.c for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Mon Jun 23 15:33:38 2014 Max Prudhomme
** Last update Tue Jun 24 18:29:34 2014 Nathan BIGAIGNON
*/

#include "t_server_options.h"

void	init_struct(t_server_options *options)
{
  options->num_port = 0;
  options->map_height = 0;
  options->map_width = 0;
  options->num_client = 1;
  options->time_exec = 100;
  options->nb_team = 0;
}
