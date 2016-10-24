/*
** t_cell.h for zappy in /Users/Zheness/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Tue May  6 12:56:06 2014 Max Prudhomme
** Last update Fri Jul 11 15:42:51 2014 Max Prudhomme
*/

#ifndef				T_CELL_H_
# define			T_CELL_H_

typedef struct s_ptr_players t_ptr_players;
typedef struct s_ptr_players_desc t_ptr_players_desc;

# include			"t_object.h"
# include			"t_players_ptr.h"

typedef struct			s_cell
{
  t_object			*object;
  t_ptr_players_desc		*pptr_list_desc;
}				t_cell;

#endif				/* !T_CELL_H_ */
