/*
** server_time_controller.h for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Wed Jul  9 18:20:17 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 12:43:28 2014 Max Prudhomme
*/

#ifndef		SERVER_TIME_CONTROLLER_H_
# define	SERVER_TIME_CONTROLLER_H_

# include	"t_utils.h"

void	clean_action_list(t_user_list *player);
int    	register_action(t_user_list *player);
int	start_scheduled_action(t_utils *utils);
int	launch_action(t_utils *utils, t_user_list *tmp);
int	time_action_controller(t_user_list *tmp);

int	user_manage_time(t_utils *utils, t_user_list *user);
int	manage_time(t_utils *utils);
int	check_end_game(t_utils *utils);
void	count_players_lvl8(t_utils *utils, int *nb_lvl8);
int	quit_game(t_utils *utils, char *team);

void	delete_egg(t_utils *utils, t_egg *egg);
int	time_eggs_hatch(t_utils *utils);
void	egg_is_hatching(t_utils *utils, t_egg *egg);
void	delete_egg(t_utils *utils, t_egg *egg);
void	egg_is_dead(t_utils *utils, t_user_list *user);

#endif		/* !SERVER_TIME_CONTROLLER_H_ */
