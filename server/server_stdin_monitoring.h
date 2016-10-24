/*
** server_stdin_monitoring.h for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Sat Jul 12 18:49:31 2014 Nathan BIGAIGNON
** Last update Sat Jul 12 20:45:15 2014 Max Prudhomme
*/

#ifndef		SERVER_STDIN_MONITORING_H_
# define	SERVER_STDIN_MONITORING_H_

# include	"t_utils.h"

# define	STDIN 0

int	stdin_monitoring(t_utils *utils);
void	broadcast_msg_to_monitors(t_utils *utils, char *str);

#endif		/* !SERVER_STDIN_MONITORING */
