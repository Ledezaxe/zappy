/*
** server_add_egg_player.h for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Sun Jul 13 12:39:21 2014 Max Prudhomme
** Last update Sun Jul 13 12:40:38 2014 Max Prudhomme
*/

#ifndef		SERVER_ADD_EGG_PLAYER_H_
# define	SERVER_ADD_EGG_PLAYER_H_

# include	"t_utils.h"

int		has_egg(t_utils *utils);
t_user_list	*get_first_free_egg(t_utils *utils);
int		add_egg_player(t_utils *utils, int socket, char *buffer);

#endif		/* !SERVER_ADD_EGG_PLAYER_H_ */
