/*
** server_command_fork.h for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Sat Jul 12 10:37:53 2014 Max Prudhomme
** Last update Sun Jul 13 12:55:01 2014 Max Prudhomme
*/

#ifndef		SERVER_COMMAND_FORK_H_
# define	SERVER_COMMAND_FORK_H_

# include	"t_utils.h"

char	*cmd_fork(t_user_list *user, t_utils *utils);
void	fork_msg_start(t_utils *utils, t_user_list *p);

#endif		/* !SERVER_COMMAND_FORK_H_ */
