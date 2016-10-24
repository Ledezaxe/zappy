/*
** server_user_inventory.h for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Thu Jun 26 11:05:59 2014 Max Prudhomme
** Last update Thu Jun 26 11:27:00 2014 Max Prudhomme
*/

#ifndef		SERVER_USER_INVENTORY_H_
# define	SERVER_USER_INVENTORY_H_

#include	"t_object.h"

void	reset_inventory(t_object *inventory);
char	*inventory_to_string(t_object *inventory);

#endif		/* !SERVER_USER_INVENTORY_H_ */
