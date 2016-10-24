/*
** reception_serveur.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Thu Jul  3 13:47:42 2014 stephane budelot
** Last update Sat Jul 12 15:41:11 2014 stephane budelot
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"ia.h"
#include	"error.h"

void		new_lvl(char *str, t_ia *ia)
{
  char		*lvl;

  if ((lvl = strstr(str, "niveau actuel :")) != NULL)
    ia->lvl = atoi(&lvl[16]);
  broadcast_elevation_end(ia->fd, ia);
  ia->broadcast_pos = -1;
  ia->elev = 0;
}

int		tri_info(t_ia *ia, char *str)
{
  char		*first;

  if (strstr(str, "message ") != NULL)
    broadcast_txt(ia, str);
  else if (strstr(str, "deplacement ") != NULL)
    return (see_map(ia));
  else if (strstr(str, "niveau actuel :") != NULL)
    new_lvl(str, ia);
  else if (str[0] >= '0' && str[0] <= '9')
    team_slot_empty(str);
  else if ((first = strstr(str, "{")) != NULL)
    {
      if ((first = strstr(str, "nourriture")) != NULL)
	{
	  if (first[11] <= '9' && first[11] >= '0')
	    recep_inventaire(str, ia);
	  else
	    return (cut_string(ia, str));
	}
      else
	return (cut_string(ia, str));
    }
  return (0);
}

void		recep_inventaire(char *str, t_ia *ia)
{
  char		*first;

  ia->cmd_i = 0;
  first = strstr(str, "nourriture");
  ia->life = atoi(&first[11]);
  first = strstr(str, "linemate");
  ia->tt_linemate = atoi(&first[9]);
  first = strstr(str, "deraumere");
  ia->tt_deraumere = atoi(&first[10]);
  first = strstr(str, "sibur");
  ia->tt_sibur = atoi(&first[6]);
  first = strstr(str, "mendiane");
  ia->tt_mendiane = atoi(&first[9]);
  first = strstr(str, "phiras");
  ia->tt_phiras = atoi(&first[7]);
  first = strstr(str, "thystame");
  ia->tt_thystame = atoi(&first[9]);
  voir_inventaire(ia);
}

void		team_slot_empty(char *str)
{
  char		val[1];

  val[0] = str[0];
  printf("Slot no use: %d.\n", atoi(val));
}
