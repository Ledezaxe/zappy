/*
** t_args.h for zappy in /Users/Zheness/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Tue May  6 18:01:45 2014 Max Prudhomme
** Last update Fri Jul  4 14:29:22 2014 Nathan BIGAIGNON
*/

#ifndef		T_ARGS_H_
# define	T_ARGS_H_

typedef struct	s_args
{
  char		**team;
  t_uint	*player_in_team;
  t_uint	nb_team;
  t_uint	time;
  t_uint	require_client_nb;
}		t_args;

#endif		/* !T_ARGS_H_ */
