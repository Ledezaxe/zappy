/*
** t_socket.h for zappy in /Users/Zheness/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Tue May  6 17:08:42 2014 Max Prudhomme
** Last update Sat Jul 12 18:00:55 2014 Nathan BIGAIGNON
*/

#ifndef			T_SOCKET_H_
# define		T_SOCKET_H_

# include		<sys/types.h>
# include		<sys/socket.h>
# include		<sys/select.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		"t_monitors.h"
# include		"t_uint.h"

typedef struct		s_socket
{
  struct sockaddr_in	sin;
  struct sockaddr	caddr;
  socklen_t		clen;
  int			backlog;
  int			listener;
  int			new;
  t_uint	       	port;
  int			fdmax;
  fd_set		master;
  fd_set		rdfs;
  char			buffer[255];
  t_monitors_desc	*monitors;
  t_uint		nb_monitor;
  t_uint		nb_client;
}			t_socket;

#endif			/* !T_SOCKET_H_ */
