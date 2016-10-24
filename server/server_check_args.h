/*
** server_check_args.h for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Thu Jun 19 15:48:22 2014 Max Prudhomme
** Last update Wed Jun 25 15:22:44 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_CHECK_ARGS_H_
# define	SERVER_CHECK_ARGS_H_

# include	"t_server_options.h"

enum	e_server_section
  {
    NUM_PORT = 0,
    MAP_WIDTH,
    MAP_HEIGHT,
    TEAM_NAME,
    NUM_CLIENT,
    TIME_EXEC,
    NONE
  };

struct	s_server_section
{
  char	name[3];
  char	type;
  void	(*fct)(char *str, t_server_options *options);
};

int	start_checking(int ac, char **av, t_server_options *options);
int	start_loop_checking(int ac, char **av, t_server_options *options);
int	check_option_exists(char *str, unsigned char *section);
int	check_index_team(char section, int *index_team, char i);
int	end_checking(t_server_options *options, int index_team, char **av);

#endif		/* !SERVER_CHECK_ARGS_H_ */
