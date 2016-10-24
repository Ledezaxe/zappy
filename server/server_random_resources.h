/*
** server_random_resources.h for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Wed Jul  9 18:15:15 2014 Max Prudhomme
** Last update Wed Jul  9 18:36:28 2014 Max Prudhomme
*/

#ifndef		SERVER_RANDOM_RESOURCES_H_
# define	SERVER_RANDOM_RESOURCES_H_

# include	"t_utils.h"

struct		s_rand_stone
{
  int		nb;
  void		(*fct)(t_utils *utils);
};

void	gen_rand_resource(t_utils *utils);
void	rand_linemate(t_utils *utils);
void	rand_deraumere(t_utils *utils);
void	rand_sibur(t_utils *utils);
void	rand_mendiane(t_utils *utils);
void	rand_phiras(t_utils *utils);
void	rand_thystame(t_utils *utils);

#endif		/* !SERVER_RANDOM_RESOURCES_H_ */
