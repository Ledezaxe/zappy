/*
** server_init_argument.h for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Thu Jun 19 17:37:14 2014 Nathan BIGAIGNON
** Last update Tue Jun 24 15:46:12 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_INIT_ARGUMENT_H_
# define	SERVER_INIT_ARGUMENT_H_

# include	"t_utils.h"

int	init_argument(t_utils *utils);
void	set_team(char **team, t_utils *utils);
void	set_require_client_nb(t_uint require_client_nb, t_utils *utils);
void	set_time(t_uint time, t_utils *utils);
void	set_nb_team(t_uint nb_team, t_utils *utils);

#endif		/* !SERVER_INIT_ARGUMENT_H_ */
