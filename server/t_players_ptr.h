/*
** t_players_ptr.h for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Fri Jul 11 11:17:35 2014 Nathan BIGAIGNON
** Last update Sat Jul 12 18:02:32 2014 Nathan BIGAIGNON
*/

#ifndef			T_PLAYERS_PTR_H_
# define		T_PLAYERS_PTR_H_

# include		"t_utils.h"
# include		"t_user_list.h"

struct		s_ptr_players
{
  t_user_list		*addr;
  struct s_ptr_players	*next;
};

struct		s_ptr_players_desc
{
  t_ptr_players		*head;
  t_ptr_players		*tail;
};

int	put_player_in_cell(t_ptr_players_desc *desc, t_user_list *p);
void	remove_player_in_cell(t_ptr_players_desc *desc, t_user_list *p);
void	free_player_ptr_replace_ptr(t_ptr_players *tmp, t_user_list *p,
				    t_ptr_players_desc *desc);
void	free_player_ptr_unique_elem(t_ptr_players *tmp,
				    t_ptr_players_desc *desc);

#endif		/* !T_PLAYERS_PTR_H_ */
