/*
** server_command_incantation.h for zappy in /Users/Zheness/Git_Repo/zappy
** 
** Made by Max Prudhomme
** Login   <max.prudhomme@epitech.net>
** 
** Started on  Sat Jul  5 18:54:40 2014 Max Prudhomme
** Last update Sat Jul 12 10:34:39 2014 Max Prudhomme
*/

#ifndef		SERVER_COMMAND_INCANTATION_H_
# define	SERVER_COMMAND_INCANTATION_H_

# include	"t_utils.h"
# include	"t_user_list.h"

typedef struct	s_stone
{
  int	linemate;
  int	deraumere;
  int	sibur;
  int	mendiane;
  int	phiras;
  int	thystame;
}		t_stone;

struct	s_lvl_up
{
  int	level;
  int	player;
  int	linemate;
  int	deraumere;
  int	sibur;
  int	mendiane;
  int	phiras;
  int	thystame;
};

extern struct s_lvl_up	g_lvl_up[7];

int	send_evolve_msg(t_utils *utils, t_user_list *user);
int	evolve_players(t_utils *utils, t_user_list *user);
void	reset_stone(t_stone *stone);
void	send_incantation_msg(t_utils *utils, t_user_list *user);
void	send_incantation_finish(t_utils *utils, t_user_list *user, int lvl);

int	start_elevation(t_utils *utils, t_user_list *user);
void	incantation_msg_start(t_utils *utils, t_user_list *p);

#endif		/* !SERVER_COMMAND_INCANTATION_H_ */
