/*
** server_command_broadcast.h for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Mon Jun 30 17:03:38 2014 Max Prudhomme
** Last update Mon Jul  7 16:27:37 2014 Max Prudhomme
*/

#ifndef		SERVER_COMMAND_BROADCAST_H_
# define	SERVER_COMMAND_BROADCAST_H_

# include	"t_user_list.h"
# include	"t_utils.h"

int	send_msg_to_users(t_utils *utils, t_user_list *user);
int	send_player_expulse(t_utils *utils, t_user_list *user);
int	broadcast_msg(t_utils *utils, int socket, int pos);
void	find_prev_cell(int *x, int *y, int *distance, t_utils *utils);
int	find_cell_pos_player(t_user_list *p, int x, int y, t_utils *utils);
void	find_horizontal_pos(t_utils *utils, int x, t_user_list *p, int *pos);
void	find_vertical_pos(t_utils *utils, int y, t_user_list *p, int *pos);
void	deplace_cell_right_left(int *x, int *distance, t_utils *utils);
void	deplace_cell_top_down(int *y, int *distance, t_utils *utils);
int	distance_from_top(int nb, int max, int y, t_utils *utils);
int	distance_from_bottom(int nb, int max, int y, t_utils *utils);
int	distance_from_left(int nb, int max, int x, t_utils *utils);
int	distance_from_right(int nb, int max, int x, t_utils *utils);

#endif		/* !SERVER_COMMAND_BROADCAST_H_ */
