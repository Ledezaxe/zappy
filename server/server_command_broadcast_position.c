/*
** server_command_broadcast_position.c for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Tue Jul  1 14:05:50 2014 Max Prudhomme
** Last update Tue Jul  1 14:57:59 2014 Max Prudhomme
*/

#include "server_command_watch.h"
#include "server_command_broadcast.h"

int	find_cell_pos_player(t_user_list *player, int x, int y, t_utils *utils)
{
  int	pos;

  if ((int) player->x == x && (int) player->y == y)
    pos = 0;
  else if ((int) player->x == x)
    find_vertical_pos(utils, y, player, &pos);
  else
    find_horizontal_pos(utils, y, player, &pos);
  return (pos);
}

void	find_vertical_pos(t_utils *utils, int y, t_user_list *player, int *pos)
{
  if (y == (int) TOP_CELL(player->y, 1))
    {
      if (player->direction == TOP)
	*pos = 1;
      else if (player->direction == RIGHT)
	*pos = 3;
      else if (player->direction == DOWN)
	*pos = 5;
      else
	*pos = 7;
    }
  else
    {
      if (player->direction == TOP)
	*pos = 5;
      else if (player->direction == RIGHT)
	*pos = 7;
      else if (player->direction == DOWN)
	*pos = 1;
      else
	*pos = 3;
    }
}

void	find_horizontal_pos(t_utils *utils, int x, t_user_list *p, int *pos)
{
  if (x == (int) LEFT_CELL(p->x, 1))
    {
      if (p->direction == TOP)
	*pos = 3;
      else if (p->direction == RIGHT)
	*pos = 5;
      else if (p->direction == DOWN)
	*pos = 7;
      else
	*pos = 1;
    }
  else
    {
      if (p->direction == TOP)
	*pos = 7;
      else if (p->direction == RIGHT)
	*pos = 1;
      else if (p->direction == DOWN)
	*pos = 3;
      else
	*pos = 5;
    }

}

void	deplace_cell_right_left(int *x, int *distance, t_utils *utils)
{
  if (distance[LEFT] < distance[RIGHT])
    *x = RIGHT_CELL(*x, 1);
  else
    *x = LEFT_CELL(*x, 1);
}

void	deplace_cell_top_down(int *y, int *distance, t_utils *utils)
{
  if (distance[TOP] < distance[DOWN])
    *y = BOTTOM_CELL(*y, 1);
  else
    *y = TOP_CELL(*y, 1);
}
