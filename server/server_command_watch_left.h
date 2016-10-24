/*
** server_command_watch_left.h for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Sat Jun 28 12:37:18 2014 Max Prudhomme
** Last update Sat Jun 28 14:55:33 2014 Max Prudhomme
*/

#ifndef		SERVER_COMMAND_WATCH_LEFT_H_
# define	SERVER_COMMAND_WATCH_LEFT_H_

# include	"t_user_list.h"
# include	"t_utils.h"

int	s_look_left(t_user_list *user, t_utils *utils, t_uint *size);
int	look_left(t_user_list *user, t_utils *utils, char *str);

#endif		/* !SERVER_COMMAND_WATCH_LEFT_H_ */
