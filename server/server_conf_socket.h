/*
** server_conf_socket.h for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Mon Jun 30 12:39:34 2014 Nathan BIGAIGNON
** Last update Tue Jul  1 10:43:45 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_CONF_SOCKET_H_
# define	SERVER_CONF_SOCKET_H_

# include	"t_utils.h"

int	socket_name(t_utils *utils);
int	conf_listener(t_utils *utils);
int	connect_socket(t_socket *s);

#endif		/* !SERVER_CONF_SOCKET_H_ */
