/*
** server_clients_controller.h for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Tue Jul  1 14:50:59 2014 Nathan BIGAIGNON
** Last update Sun Jul  6 12:57:22 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_CLIENTS_CONTROLLER_H_
# define	SERVER_CLIENTS_CONTROLLER_H_

# include	"t_utils.h"

int	add_monitor(t_utils *utils, int socket);
int	add_ia(t_utils *utils, int socket, char *buffer);
int	check_team_name(t_utils *utils, char *team);
int	store_socket_in_array(t_utils *utils, int socket, int flag);
int	store_ia(t_utils *utils, char *buffer, int i, int socket);

#endif		/* !SERVER_CLIENTS_CONTROLLER_H_ */
