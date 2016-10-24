/*
** server_add_player.h for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Wed Jun 25 15:42:09 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 11:02:36 2014 Max Prudhomme
*/

#ifndef		SERVER_ADD_PLAYER_H_
# define	SERVER_ADD_PLAYER_H_

# include	"t_utils.h"
# include	"t_user_list.h"

int	add_player(t_utils *utils, int id, char *team, int egg);
int	init_player(t_map *map, int id, t_user_list *p, char *team);
void	reset_inventory(t_object *inventory);

#endif		/* !SERVER_ADD_PLAYER_H_ */
