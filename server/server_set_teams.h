/*
** server_set_teams.h for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Mon Jun 23 14:16:03 2014 Max Prudhomme
** Last update Wed Jun 25 18:55:48 2014 Max Prudhomme
*/

#ifndef		SERVER_SET_TEAMS_H_
# define	SERVER_SET_TEAMS_H_

# include	"server_check_args.h"

void	set_team_name(char *str, t_server_options *options);
int	create_table(t_server_options *options, int index_team, char **av);
int	validation_teams(char **teams, t_uint nb_team);
int	is_identic(char *str1, char *str2);

#endif		/* !SERVER_SET_TEAMS_H_ */
