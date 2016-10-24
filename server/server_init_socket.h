/*
** server_init_socket.h for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Thu Jun 19 16:00:41 2014 Nathan BIGAIGNON
** Last update Fri Jun 27 16:50:56 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_INIT_SOCKET_H_
# define	SERVER_INIT_SOCKET_H_

# include	"t_utils.h"

int	init_socket(t_utils *utils);
void	set_port(t_uint port, t_utils *utils);
int	create_socket(void);

#endif		/* !SERVER_INIT_SOCKET_H_ */
