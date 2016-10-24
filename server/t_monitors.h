/*
** t_monitors.h for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Fri Jul 11 16:23:44 2014 Nathan BIGAIGNON
** Last update Fri Jul 11 16:51:39 2014 Nathan BIGAIGNON
*/

#ifndef			T_MONITORS_H_
# define		T_MONITORS_H_

typedef struct		s_monitors
{
  int			id;
  struct s_monitors	*next;
}			t_monitors;

typedef struct		s_monitors_desc
{
  t_monitors		*head;
  t_monitors		*tail;
}			t_monitors_desc;

int    	add_monitors_in_list(t_monitors_desc *desc, int socket);
void   	rm_monitors_from_list(t_monitors_desc *desc, int socket);
void	free_monitors_unique_elem(t_monitors *tmp, t_monitors_desc *desc);
void	free_monitors_replace_ptr(t_monitors *tmp, int socket,
				  t_monitors_desc *desc);

#endif			/* !T_MONITORS_H_ */
