/*
** t_map.h for zappy in /Users/Zheness/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Tue May  6 12:13:08 2014 Max Prudhomme
** Last update Sun Jul  6 15:35:51 2014 Nathan BIGAIGNON
*/

#ifndef		T_MAP_H_
# define	T_MAP_H_

# include	"t_cell.h"

typedef struct	s_map
{
  t_cell	***cell;
  t_uint	width;
  t_uint	height;
}		t_map;

#endif		/* !T_MAP_H_ */
