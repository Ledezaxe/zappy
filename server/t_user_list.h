/*
** t_user_list.h for zappy in /Users/Zheness/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Tue May  6 14:07:21 2014 Max Prudhomme
** Last update Sun Jul 13 12:41:12 2014 Max Prudhomme
*/

#ifndef			T_USER_LIST_H_
# define		T_USER_LIST_H_

typedef struct s_user_list t_user_list;

# include		"t_utils.h"

enum			e_direction
  {
    TOP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
  };

typedef struct s_action
{
  char		*(*fct)(t_user_list *user, t_utils *utils);
  int		start;
  char		buff[255];
}		t_action;

struct		s_user_list
{
  unsigned char		direction;
  unsigned char		level;
  t_object		*inventory;
  char			*team;
  t_action		action[10];
  int			life;
  int			cursor;
  int			egg;
  t_uint		id;
  t_uint		x;
  t_uint		y;
  struct s_user_list	*next;
};

struct		s_user_desc
{
  t_user_list		*head;
  t_user_list		*tail;
  int			size;
};

int	add_player_in_list(t_user_desc *desc, t_user_list *player);

#endif			/* !T_USER_LIST_H_ */
