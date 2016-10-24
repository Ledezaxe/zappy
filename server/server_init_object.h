/*
** server_init_object.h for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Thu Jun 19 20:37:22 2014 Nathan BIGAIGNON
** Last update Fri Jul 11 11:32:51 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_INIT_OBJECT_H_
# define	SERVER_INIT_OBJECT_H_

# include	"t_utils.h"

int	init_object(t_utils *utils);
void	set_player_array(t_user_list **player);
void	reset_object(t_object *object);

#endif		/* !SERVER_INIT_OBJECT_H_ */
