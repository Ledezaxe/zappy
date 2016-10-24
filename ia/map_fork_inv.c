/*
** map_fork_inv.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Sun Jul  6 15:59:51 2014 stephane budelot
** Last update Sun Jul 13 14:40:40 2014 stephane budelot
*/

#include	<stdio.h>

#include	"ia.h"

void		voir_inventaire(t_ia *ia)
{
  printf("nourriture:%d, lin:%d, der:%d, sib:%d, men:%d, phi:%d, thy:%d\n",
	 ia->life, ia->tt_linemate, ia->tt_deraumere, ia->tt_sibur,
	 ia->tt_mendiane, ia->tt_phiras, ia->tt_thystame);
}

int		inventaire(t_ia *ia)
{
  if (ia->dead == 1)
    return (0);
  if (ia->cmd_i == 0)
    {
      printf("Demande d'inventaire\n");
      if (send_serv(ia->fd, "inventaire\n") == -1)
	return (-1);
      ia->cmd_i = 1;
    }
  while (ia->cmd_i == 1)
    if (communication_ia(ia) == -1)
      return (-1);
  return (0);
}

int		do_fork(t_ia *ia)
{
  if (communication_ia(ia) == -1)
    return (-1);
  printf("Fait un fork\n");
  return (send_serv(ia->fd, "fork\n"));
}

int		see_map(t_ia *ia)
{
  if (ia->dead == 1)
    return (0);
  if (ia->cmd_v == 0)
    {
      printf("Demande a voir la map\n");
      if (send_serv(ia->fd, "voir\n") == -1)
	return (-1);
      ia->cmd_v = 1;
    }
  while (ia->cmd_v == 1)
    if (communication_ia(ia) == -1)
      return (-1);
  return (0);
}
