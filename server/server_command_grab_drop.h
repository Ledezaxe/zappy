/*
** server_command_grab_drop.h for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Thu Jul  3 17:23:54 2014 Max Prudhomme
** Last update Mon Jul  7 16:13:15 2014 Max Prudhomme
*/

#ifndef		SERVER_COMMAND_GRAB_DROP_H_
# define	SERVER_COMMAND_GRAB_DROP_H_

# include	"server_command_watch.h"
# include	"t_object.h"
# include	"t_user_list.h"

struct		s_grab_drop
{
  unsigned char	type;
  char		name[15];
  int		(*fct_grab)(t_object *object, t_user_list *user);
  int		(*fct_drop)(t_object *object, t_user_list *user);
};

int	grab_linemate(t_object *object, t_user_list *user);
int	grab_deraumere(t_object *object, t_user_list *user);
int	grab_sibur(t_object *object, t_user_list *user);
int	grab_mendiane(t_object *object, t_user_list *user);
int	grab_phiras(t_object *object, t_user_list *user);
int	grab_thystame(t_object *object, t_user_list *user);
int	grab_food(t_object *object, t_user_list *user);

int	drop_linemate(t_object *object, t_user_list *user);
int	drop_deraumere(t_object *object, t_user_list *user);
int	drop_sibur(t_object *object, t_user_list *user);
int	drop_mendiane(t_object *object, t_user_list *user);
int	drop_phiras(t_object *object, t_user_list *user);
int	drop_thystame(t_object *object, t_user_list *user);
int	drop_food(t_object *object, t_user_list *user);

int	send_objects_content(t_utils *utils, t_user_list *user);

extern struct s_grab_drop	g_grab_drop[7];

#endif		/* !SERVER_COMMAND_GRAB_DROP_H_ */
