/*
** server_command_broadcast_distance.c for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Mon Jun 30 18:03:30 2014 Max Prudhomme
** Last update Mon Jun 30 18:17:35 2014 Max Prudhomme
*/

#include "server_command_watch.h"
#include "server_command_broadcast.h"

int	distance_from_top(int nb, int max, int y, t_utils *utils)
{
  if (y == max)
    return (nb);
  return (distance_from_top(nb + 1, max, TOP_CELL(y, 1), utils));
}

int	distance_from_bottom(int nb, int max, int y, t_utils *utils)
{
  if (y == max)
    return (nb);
  return (distance_from_bottom(nb + 1, max, BOTTOM_CELL(y, 1), utils));
}

int	distance_from_left(int nb, int max, int x, t_utils *utils)
{
  if (x == max)
    return (nb);
  return (distance_from_left(nb + 1, max, LEFT_CELL(x, 1), utils));
}

int	distance_from_right(int nb, int max, int x, t_utils *utils)
{
  if (x == max)
    return (nb);
  return (distance_from_right(nb + 1, max, RIGHT_CELL(x, 1), utils));
}
