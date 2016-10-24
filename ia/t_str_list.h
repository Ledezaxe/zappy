/*
** t_str_list.h for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Sat Jul 12 16:55:17 2014 stephane budelot
** Last update Sat Jul 12 18:39:53 2014 stephane budelot
*/

#ifndef			T_STR_LIST_H_
# define		T_STR_LIST_H_

typedef struct		s_str_list
{
  char			*str;
  struct s_str_list	*next;
}			t_str_list;

typedef struct		s_str_list_desc
{
  t_str_list		*end;
  t_str_list		*beg;
  int			size_str;
}			t_str_list_desc;

void	init_str_list_desc(t_str_list_desc *desc);
int	add_in_str_list(t_str_list_desc *desc, char *str);
void	dump_str_list(t_str_list_desc *desc);
void	free_str_list(t_str_list_desc *desc, char *buff);

#endif		/* !T_STR_LIST_H_ */
