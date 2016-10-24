/*
** client.h for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Wed Jul  2 10:34:39 2014 stephane budelot
** Last update Mon Jul  7 16:58:15 2014 stephane budelot
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

#include	<stdlib.h>

typedef struct	s_client
{
  char		*ip;
  int		port;
  char		*neq;
  int		fd;
}		t_client;

int		main(int argc, char **argv);
int		verif_cmd(int argc, char **argv);
int		client(char *ip, int port, char *neq);
int		communicate(int fd, char *neq);
int		do_client(int sc, char *neq);
int             send_serv_cli(int sc);
char		*strndup(const char *s, size_t n);


#endif		/* !CLIENT_H_ */
