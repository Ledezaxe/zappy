/*
** server_command_inventory.c for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Mon Jun 30 16:48:45 2014 Max Prudhomme
** Last update Wed Jul  2 14:25:59 2014 Max Prudhomme
*/

#include "t_user_list.h"
#include "t_utils.h"
#include "server_user_inventory.h"

char	*cmd_inventory(t_user_list *user, t_utils *utils)
{
  (void)utils;
  return (inventory_to_string(user->inventory));
}
