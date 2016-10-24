/*
** communication_ia.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Wed Jul  2 14:34:41 2014 stephane budelot
** Last update Sun Jul 13 12:46:12 2014 stephane budelot
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
#include	<unistd.h>

#include	"ia.h"
#include	"error.h"
#include	"t_str_list.h"

static char		*complet_str(t_str_list_desc *desc)
{
  t_str_list		*tmp;
  char			*buff;

  tmp = desc->beg;
  if ((buff = malloc(sizeof(char) * (desc->size_str) + 1)) == NULL)
    return (NULL);
  memset(buff, 0, (desc->size_str));
  while (tmp != NULL)
    {
      strcat(buff, tmp->str);
      tmp = tmp->next;
    }
  return (buff);
}

int			recep_serv(int sc, t_ia *ia)
{
  char			str[4751];
  char			*buff;
  int			bytes;
  t_str_list_desc	desc;

  init_str_list_desc(&desc);
  bytes = 4750;
  while (bytes >= 4750)
    {
      memset(str, 0, 4750);
      if ((bytes = recv(sc, str, 4750, 0)) == 0)
	return (raise_error("Server closed", __FUNCTION__, -1));
      if (bytes == -1)
	return (std_raise_error(__FUNCTION__, -1));
      if (add_in_str_list(&desc, str) == -1)
	return (-1);
    }
  if (strcmp("mort\n", str) == 0)
    ia->dead = 1;
  if ((buff = complet_str(&desc)) == NULL)
    return (-1);
  if (tri_info(ia, buff) == -1)
    return (-1);
  free_str_list(&desc, buff);
  return (0);
}

int		send_serv(int sc, char *str)
{
  if (send(sc, str, strlen(str), 0) == -1)
    return (std_raise_error(__FUNCTION__, -1));
  return (0);
}

int		communication_ia(t_ia *ia)
{
  fd_set		read_field;
  fd_set		write_field;
  struct timeval	timeout;

  FD_ZERO(&read_field);
  FD_ZERO(&write_field);
  FD_SET(ia->fd, &read_field);
  FD_SET(ia->fd, &write_field);
  FD_SET(1, &write_field);
  FD_SET(0, &read_field);
  timeout.tv_sec = 0;
  timeout.tv_usec = 2000;
  if (select(ia->fd + 1, &read_field, NULL, NULL, &timeout) != -1)
    {
      if (FD_ISSET(ia->fd, &read_field))
	if (recep_serv(ia->fd, ia) == -1)
	  return (-1);
    }
  else
    return (std_raise_error(__FUNCTION__, -1));
  return (0);
}
