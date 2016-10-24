/*
** server_command_forward.h for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Fri Jul  4 15:24:46 2014 Max Prudhomme
** Last update Fri Jul 11 14:02:36 2014 Max Prudhomme
*/

#ifndef		SERVER_COMMAND_FORWARD_H_
# define	SERVER_COMMAND_FORWARD_H_

# include	"t_user_list.h"
# include	"t_utils.h"

struct		s_move_direction
{
  unsigned char	direction;
  void		(*fct_move)(t_utils *utils, t_user_list *user);
};

void	move_player(t_utils *utils, t_user_list *user);

void	move_up(t_utils *utils, t_user_list *user);
void	move_down(t_utils *utils, t_user_list *user);
void	move_left(t_utils *utils, t_user_list *user);
void	move_right(t_utils *utils, t_user_list *user);

#endif		/* !SERVER_COMMAND_FORWARD_H_ */
