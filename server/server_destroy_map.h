/*
** server_destroy_map.h for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Tue Jun 24 18:40:52 2014 Nathan BIGAIGNON
** Last update Fri Jul 11 20:27:47 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_DESTROY_MAP_H_
# define	SERVER_DESTROY_MAP_H_

# include	"t_utils.h"
# include	"t_user_list.h"
# include	"t_players_ptr.h"

void	destroy_map(t_utils *utils);
void	destroy_cell(t_utils *utils);
void	destroy_pptr_in_cell(t_ptr_players_desc *desc);

#endif		/* !SERVER_DESTROY_MAP_H_ */
