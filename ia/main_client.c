/*
** main_client.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Fri Jun 27 09:34:21 2014 stephane budelot
** Last update Tue Jul  8 16:38:05 2014 stephane budelot
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include        <sys/select.h>
#include        <sys/time.h>
#include        <sys/types.h>
#include        <unistd.h>

#include	"error.h"
#include	"client.h"
#include	"ia.h"

static void	free_all(t_client *cl)
{
  free(cl->ip);
  free(cl->neq);
}

static int	boucle_fork(t_client *cl)
{
  int		fd_client;

  if ((fd_client = client(cl->ip, cl->port, cl->neq)) == EXIT_FAILURE)
    return (-1);
  new_ia(fd_client);
  if (close(fd_client) == -1)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  return (0);
}

static int	save_ip_port_neq(t_client *cl, int argc, char **argv)
{
  cl->port = atoi(argv[2]);
  if ((cl->neq = malloc(strlen(argv[1]) + 2)) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  cl->neq = strcpy(cl->neq, argv[1]);
  if (argc == 4)
    {
      if ((cl->ip = strndup(argv[3], strlen(argv[3]))) == NULL)
	return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
    }
  else
    if ((cl->ip = strndup("127.0.0.1", strlen("127.0.0.1"))) == NULL)
      return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  return (0);
}

int		main(int argc, char **argv)
{
  t_client	cl;

  if (verif_cmd(argc, argv) != 0)
    return (-1);
  if (save_ip_port_neq(&cl, argc, argv) != EXIT_FAILURE)
    boucle_fork(&cl);
  free_all(&cl);
  return (0);
}
