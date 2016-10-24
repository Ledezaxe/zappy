/*
** server_send_msg.h for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Sat Jul  5 20:15:06 2014 Nathan BIGAIGNON
** Last update Sun Jul  6 01:35:04 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_SEND_MSG_H_
# define	SERVER_SEND_MSG_H_

# include	"t_utils.h"

int	send_msg_to_monitors(t_utils *utils, char *msg);
int	send_msg_to_client(int socket, char *msg);

#endif		/* !SERVER_SEND_MSG_H_ */
