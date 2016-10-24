/*
** t_server_options.h for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Mon Jun 23 14:51:17 2014 Max Prudhomme
** Last update Sat Jul 12 18:00:08 2014 Nathan BIGAIGNON
*/

#ifndef		T_SERVER_OPTIONS_H_
# define	T_SERVER_OPTIONS_H_

# include	<stdlib.h>
# include	"t_uint.h"

typedef struct	s_server_options
{
  t_uint	num_port;
  t_uint	map_height;
  t_uint	map_width;
  t_uint	num_client;
  t_uint	time_exec;
  t_uint	nb_team;
  char		**team_name;
}		t_server_options;

void	init_struct(t_server_options *options);

#endif		/* !T_SERVER_OPTIONS_H_ */
