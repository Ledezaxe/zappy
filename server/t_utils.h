/*
** t_utils.h for zappy in /Users/Zheness/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Tue May  6 12:04:24 2014 Max Prudhomme
** Last update Sat Jul 12 18:04:48 2014 Nathan BIGAIGNON
*/

#ifndef		T_UTILS_H_
# define	T_UTILS_H_

typedef struct s_utils t_utils;
typedef struct s_user_desc t_user_desc;
typedef struct s_egg_desc t_egg_desc;

# include	"t_map.h"
# include	"t_socket.h"
# include	"t_args.h"
# include	"t_egg.h"

# define	CELL utils->map->cell
# define	SOCKET utils->socket
# define	MAP utils->map

struct		s_utils
{
  t_map		*map;
  t_socket	*socket;
  t_args	*args;
  t_user_desc	*user;
  t_egg_desc	*egg;
};

#endif		/* !T_UTILS_H_ */
