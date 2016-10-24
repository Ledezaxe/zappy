/*
** server_command_watch_size.h for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Sat Jun 28 12:57:46 2014 Max Prudhomme
** Last update Fri Jul 11 16:43:34 2014 Max Prudhomme
*/

#ifndef		SERVER_COMMAND_WATCH_SIZE_H_
# define	SERVER_COMMAND_WATCH_SIZE_H_

# include	"server_command_watch.h"
# include	"t_utils.h"
# include	"t_cell.h"

int	size_append_cell_content(t_cell *c, t_uint *size, t_user_list *user);
int	size_append_cell_object(t_cell *cell, t_uint *size_alloc);
int	size_append_element(unsigned char type, t_uint *size_alloc, t_uint max);
int	size_append_cell_player(t_cell *c, t_uint *s, t_user_list *user);

#endif		/* !SERVER_COMMAND_WATCH_SIZE_H_ */
