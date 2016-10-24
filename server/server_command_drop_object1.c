/*
** server_command_drop_object1.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Fri Jul  4 13:57:35 2014 Max Prudhomme
** Last update Fri Jul  4 14:22:32 2014 Max Prudhomme
*/

#include "server_command_grab_drop.h"

int	drop_linemate(t_object *object, t_user_list *user)
{
  if (user->inventory->linemate >= 1)
    {
      object->linemate += 1;
      user->inventory->linemate -= 1;
      return (1);
    }
  return (0);
}

int	drop_deraumere(t_object *object, t_user_list *user)
{
  if (user->inventory->deraumere >= 1)
    {
      object->deraumere += 1;
      user->inventory->deraumere -= 1;
      return (1);
    }
  return (0);
}

int	drop_sibur(t_object *object, t_user_list *user)
{
  if (user->inventory->sibur >= 1)
    {
      object->sibur += 1;
      user->inventory->sibur -= 1;
      return (1);
    }
  return (0);
}

int	drop_mendiane(t_object *object, t_user_list *user)
{
  if (user->inventory->mendiane >= 1)
    {
      object->mendiane += 1;
      user->inventory->mendiane -= 1;
      return (1);
    }
  return (0);
}
