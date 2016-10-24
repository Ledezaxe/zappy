/*
** server_command_grab_object2.c for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Fri Jul  4 13:39:52 2014 Max Prudhomme
** Last update Fri Jul  4 14:22:10 2014 Max Prudhomme
*/

#include "server_command_grab_drop.h"

int	grab_phiras(t_object *object, t_user_list *user)
{
  if (object->phiras >= 1)
    {
      object->phiras -= 1;
      user->inventory->phiras += 1;
      return (1);
    }
  return (0);
}

int	grab_thystame(t_object *object, t_user_list *user)
{
  if (object->thystame >= 1)
    {
      object->thystame -= 1;
      user->inventory->thystame += 1;
      return (1);
    }
  return (0);
}

int	grab_food(t_object *object, t_user_list *user)
{
  if (object->food >= 1)
    {
      object->food -= 1;
      user->inventory->food += 1;
      return (1);
    }
  return (0);
}
