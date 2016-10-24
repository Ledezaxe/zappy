/*
** server_init_map.h for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Thu Jun 19 17:30:12 2014 Nathan BIGAIGNON
** Last update Tue Jun 24 16:51:42 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_INIT_MAP_H_
# define	SERVER_INIT_MAP_H_

# include	"t_utils.h"

void	set_width(t_uint width, t_utils *utils);
void	set_height(t_uint height, t_utils *utils);
int	init_map(t_utils *utils);
int	init_cell(t_utils *utils);

#endif		/* !SERVER_INIT_MAP_H_ */
