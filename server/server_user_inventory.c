/*
** server_user_inventory.c for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Thu Jun 26 11:07:23 2014 Max Prudhomme
** Last update Thu Jul  3 11:23:30 2014 Max Prudhomme
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server_user_inventory.h"
#include "error.h"

void	reset_inventory(t_object *inventory)
{
  inventory->linemate = 0;
  inventory->deraumere = 0;
  inventory->sibur = 0;
  inventory->mendiane = 0;
  inventory->phiras = 0;
  inventory->thystame = 0;
  inventory->food = 10;
  inventory->egg = 0;
}

char		*inventory_to_string(t_object *inventory)
{
  char		*str;
  t_uint	len;
  t_uint	slen;

  len = 81 + inventory->linemate + inventory->deraumere + inventory->sibur
    + inventory->mendiane + inventory->phiras + inventory->thystame
    + inventory->food;
  str = malloc(sizeof(char) * len + 1);
  if (str == NULL)
    {
      std_raise_error(__FUNCTION__, -1);
      return (NULL);
    }
  sprintf(str, "{nourriture %d, linemate %d, deraumere %d", inventory->food,
	  inventory->linemate, inventory->deraumere);
  slen = strlen(str);
  sprintf(&str[slen], ", sibur %d, mendiane %d, phiras %d, thystame %d}\n",
	  inventory->sibur, inventory->mendiane, inventory->phiras,
	  inventory->thystame);
  return (str);
}
