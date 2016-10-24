/*
** server_loop.h for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Mon Jun 30 16:51:10 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 21:12:10 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_LOOP_H_
# define	SERVER_LOOP_H_

# define	QUIT 42

# include	"t_utils.h"

int	server_loop(t_utils *utils);
int	socket_monitoring(t_utils *utils, int i);
int	new_connection(t_utils *utils);
int	init_pre_req(t_utils *utils);
int	set_select_attr(t_utils *utils, char *ok);

#endif		/* !SERVER_LOOP_H_ */
