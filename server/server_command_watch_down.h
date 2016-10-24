/*
** server_command_watch_down.h for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Sat Jun 28 12:37:18 2014 Max Prudhomme
** Last update Sat Jun 28 14:52:56 2014 Max Prudhomme
*/

#ifndef		SERVER_COMMAND_WATCH_DOWN_H_
# define	SERVER_COMMAND_WATCH_DOWN_H_

# include	"t_user_list.h"
# include	"t_utils.h"

int	s_look_down(t_user_list *user, t_utils *util, t_uint *size_alloc);
int	look_down(t_user_list *user, t_utils *utils, char *str);

#endif		/* !SERVER_COMMAND_WATCH_DOWN_H_ */
