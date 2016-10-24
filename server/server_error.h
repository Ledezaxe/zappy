/*
** server_error.h for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Tue Jul  1 12:14:04 2014 Nathan BIGAIGNON
** Last update Wed Jul  9 14:49:23 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_ERROR_H_
# define	SERVER_ERROR_H_

# include	"t_utils.h"

int	recv_error(t_utils *utils, int socket);
void	free_player(t_utils *utils, int socket);
void	free_player_unique_elem(t_user_list *tmp, t_utils *utils);
void	free_player_replace_ptr(t_user_list *tmp, t_utils *utils, int socket);

#endif		/* !SERVER_ERROR_H_ */
