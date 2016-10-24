/*
** server_set_options.c for zappt in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Mon Jun 23 14:04:43 2014 Max Prudhomme
** Last update Thu Jul 10 18:26:47 2014 Max Prudhomme
*/

#include <stdlib.h>
#include "server_set_options.h"

void	set_num_port(char *str, t_server_options *options)
{
  int	i;

  i = atoi(str);
  options->num_port = (i <= 0 || i >= 20000) ? 0 : i;
}

void	set_map_height(char *str, t_server_options *options)
{
  int	i;

  i = atoi(str);
  options->map_height = (i <= 0 || i >= 1000000) ? 0 : i;
}

void	set_map_width(char *str, t_server_options *options)
{
  int	i;

  i = atoi(str);
  options->map_width = (i <= 0 || i >= 1000000) ? 0 : i;
}

void	set_num_client(char *str, t_server_options *options)
{
  int	i;

  i = atoi(str);
  options->num_client = (i <= 0 || i >= 50000) ? 0 : i;
}

void	set_time_exec(char *str, t_server_options *options)
{
  int	i;

  i = atoi(str);
  options->time_exec = (i <= 0 || i >= 1000000) ? 0 : i;
}
