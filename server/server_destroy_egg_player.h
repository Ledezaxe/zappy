/*
** server_destroy_egg_player.h for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Sun Jul 13 12:50:52 2014 Max Prudhomme
** Last update Sun Jul 13 12:52:39 2014 Max Prudhomme
*/

#ifndef		SERVER_DESTROY_EGG_PLAYER_H_
# define	SERVER_DESTROY_EGG_PLAYER_H_

# include	"t_utils.h"

void	delete_egg_player(t_utils *utils, t_user_list *user);
  void	free_egg_player_unique_elem(t_user_list *tmp, t_utils *utils);
void	free_egg_player_replace_ptr(t_user_list *tmp, t_utils *utils,
				    t_user_list *user);

#endif		/* !SERVER_DESTROY_EGG_PLAYER_H_ */
