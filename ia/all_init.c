/*
** all_init.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Fri Jul  4 11:19:41 2014 stephane budelot
** Last update Fri Jul 11 17:02:40 2014 stephane budelot
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

#include	"ia.h"
#include	"error.h"

void		init_struct_map(t_ia *m)
{
  int		i;
  int		j;

  i = 0;
  while (i != 87)
    {
      j = 0;
      while (j != 7)
	{
	  m->lvl8[i][j] = 0;
	  j++;
	}
      i++;
    }
}

void		init_ia(t_ia *ia)
{
  ia->lvl = 1;
  ia->life = 10;
  ia->cmd_v = 0;
  ia->cmd_i = 0;
  ia->broadcast_pos = -1;
  ia->elev = 0;
  ia->nbr_here = 0;
  ia->tt_linemate = 0;
  ia->tt_deraumere = 0;
  ia->tt_sibur = 0;
  ia->tt_mendiane = 0;
  ia->tt_phiras = 0;
  ia->tt_thystame = 0;
  ia->dead = 0;
  init_struct_map(ia);
}
