/*
** server_set_options.h for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Mon Jun 23 14:08:07 2014 Max Prudhomme
** Last update Tue Jun 24 14:24:31 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_SET_OPTIONS_H_
# define	SERVER_SET_OPTIONS_H_

# include	"t_server_options.h"
# include	"server_check_args.h"

void	set_num_port(char *str, t_server_options *options);
void	set_map_height(char *str, t_server_options *options);
void	set_map_width(char *str, t_server_options *options);
void	set_num_client(char *str, t_server_options *options);
void	set_time_exec(char *str, t_server_options *options);

#endif		/* !SERVER_SET_OPTIONS_H_ */
