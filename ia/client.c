/*
** main.c for $ in /home/rouane_q/projets/unix/ftp
** 
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
** 
** Started on  Tue Apr  8 14:54:29 2014 quentin rouanet
** Last update Mon Jul  7 17:19:02 2014 stephane budelot
*/

#include	<sys/socket.h>
#include	<sys/types.h>
#include	<arpa/inet.h>
#include	<netinet/in.h>
#include	<netdb.h>
#include	<stdlib.h>
#include	<strings.h>
#include	<string.h>
#include	<stdio.h>
#include        <sys/select.h>
#include        <sys/time.h>
#include        <unistd.h>

#include	"error.h"
#include	"client.h"

int			send_serv_cli(int sc)
{
  char			str[4751];

  memset(str, 0, 4750);
  if (read(0, str, 4750) < 0)
    return (std_raise_error(__FUNCTION__, -1));
  if (send(sc, str, 4750, 0) == -1)
    return (std_raise_error(__FUNCTION__, -1));
  return (0);
}

int			do_client(int sc, char *neq)
{
  char			str[4751];
  static int		compt = 0;
  int			bytes;

  memset(str, 0, 4750);
  if ((bytes = recv(sc, str, 4750, 0)) < 0)
    return (std_raise_error(__FUNCTION__, -1));
  else if (bytes == 0)
    return (raise_error("Server closed", __FUNCTION__, -1));
  printf("%s", str);
  if (strcmp(str, "BIENVENUE\n") == 0)
    if (send(sc, neq, strlen(neq), 0) == -1)
      return (std_raise_error(__FUNCTION__, -1));
  ++compt;
  if (compt == 3)
    return (0);
  return (1);
}

int			communicate(int fd, char *neq)
{
  fd_set		read_field;
  fd_set		write_field;
  int			quit;

  quit = 1;
  while (quit && (quit != -1))
    {
      FD_ZERO(&read_field);
      FD_ZERO(&write_field);
      FD_SET(fd, &read_field);
      FD_SET(fd, &write_field);
      FD_SET(1, &write_field);
      FD_SET(0, &read_field);
      if (select(fd + 1, &read_field, &write_field, NULL, NULL) != -1)
	{
	  if (FD_ISSET(fd, &read_field))
	    quit = do_client(fd, neq);
	  if (FD_ISSET(0, &read_field))
	    quit = send_serv_cli(fd);
	}
      else
	return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
    }
  return (quit);
}

int			client(char *ip, int port, char *neq)
{
  struct protoent	*proto;
  struct sockaddr_in	sai;
  int			fd;

  proto = getprotobyname("TCP");
  if ((fd = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
    return (std_raise_error( __FUNCTION__, EXIT_FAILURE));
  sai.sin_family = AF_INET;
  sai.sin_port = htons(port);
  sai.sin_addr.s_addr = inet_addr(ip);
  if (connect(fd, (struct sockaddr *)&sai, sizeof(sai)) == -1)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  if (communicate(fd, strcat(neq, "\n")) == EXIT_FAILURE)
    return (-1);
  return (fd);
}
