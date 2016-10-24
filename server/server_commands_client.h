/*
** server_commands_client.h for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Tue Jul  1 11:02:09 2014 Nathan BIGAIGNON
** Last update Sat Jul 12 16:57:45 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_COMMANDS_CLIENT_H_
# define	SERVER_COMMANDS_CLIENT_H_

# include	<stdlib.h>
# include	"t_utils.h"

struct	s_command
{
  char	name[15];
  char	*(*fct)(t_user_list *user, t_utils *utils);
  int	time;
};

extern struct s_command g_ia[12];

struct	s_command_gui
{
  char	name[15];
  char	*(*fct)(int socket, t_utils *utils);
};

int	command_exists(char *str, char *cmd);
int	input_controller(t_utils *utils, int socket);
int	command_dispatcher(char *cmd, t_utils *utils, int socket);

char	*cmd_forward(t_user_list *user, t_utils *utils);
char	*cmd_right(t_user_list *user, t_utils *utils);
char	*cmd_left(t_user_list *user, t_utils *utils);
char	*cmd_watch(t_user_list *user, t_utils *utils);
char	*cmd_inventory(t_user_list *user, t_utils *utils);
char	*cmd_grab(t_user_list *user, t_utils *utils);
char	*cmd_drop(t_user_list *user, t_utils *utils);
char	*cmd_expulse(t_user_list *user, t_utils *utils);
char	*cmd_broadcast(t_user_list *user, t_utils *utils);
char	*cmd_fork(t_user_list *user, t_utils *utils);
char	*cmd_connect_nbr(t_user_list *user, t_utils *utils);
char	*cmd_incantation(t_user_list *user, t_utils *utils);

char	*cmd_gui_map_size(int socket, t_utils *utils);
char	*cmd_gui_case_content(int socket, t_utils *utils);
char	*cmd_gui_map_content(int socket, t_utils *utils);
char	*cmd_gui_team_name(int socket, t_utils *utils);
char	*cmd_gui_pos_player(int socket, t_utils *utils);
char	*cmd_gui_lvl_player(int socket, t_utils *utils);
char	*cmd_gui_inventory_player(int socket, t_utils *utils);
char	*cmd_gui_get_time(int socket, t_utils *utils);
char	*cmd_gui_edit_time(int socket, t_utils *utils);
void	case_content(int x, int y, t_utils *utils, int socket);

#endif		/* !SERVER_COMMANDS_CLIENT_H_ */
