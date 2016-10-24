/*
** t_egg.h for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Fri Jul 11 18:37:12 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 10:51:09 2014 Max Prudhomme
*/

#ifndef		T_EGG_H_
# define	T_EGG_H_

# include	"t_utils.h"

typedef	struct	s_egg
{
  t_uint	x;
  t_uint	y;
  t_uint	direction;
  int		id;
  int		life;
  struct s_egg *next;
}		t_egg;

struct s_egg_desc
{
  t_egg		*head;
  t_egg		*tail;
  int		index;
};

int	init_egg_list(t_utils *utils);
int	add_egg_in_list(t_egg_desc *desc, t_utils *utils);
void	rm_egg_from_list(t_egg_desc *desc, t_egg *elem);
void	free_egg_unique_elem(t_egg *tmp, t_egg_desc *desc);
void	free_egg_replace_ptr(t_egg *tmp, t_egg *elem, t_egg_desc *desc);

#endif		/* !T_EGG_H_ */
