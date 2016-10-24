/*
** server_search_func.h for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Sun Jul  6 12:06:28 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 11:06:05 2014 Max Prudhomme
*/

#ifndef		SERVER_SEARCH_FUNC_H_
# define	SERVER_SEARCH_FUNC_H_

# include	"t_utils.h"

t_user_list	*get_user_from_id(t_utils *utils, int socket);
t_user_list	*get_egg_from_id(t_utils *utils, int socket);
int		is_monitor(t_monitors_desc *desc, int socket);
int		get_direction(unsigned char direction);
int		is_ia(t_user_desc *desc, int socket);

#endif		/* !SERVER_SEARCH_FUNC_H_ */
