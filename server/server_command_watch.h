/*
** server_command_watch.h for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Sat Jun 28 12:05:13 2014 Max Prudhomme
** Last update Sat Jul 12 18:07:43 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_COMMAND_WATCH_H_
# define	SERVER_COMMAND_WATCH_H_

# include	"t_user_list.h"
# include	"t_utils.h"
# include	"t_map.h"
# include	"t_cell.h"
# include	"server_command_watch_size.h"

enum e_element
  {
    LINEMATE = 0,
    DERAUMERE = 1,
    SIBUR = 2,
    MENDIANE = 3,
    PHIRAS = 4,
    THYSTAME = 5,
    FOOD = 6,
    EGG = 7,
    PLAYER = 8
  };

struct		s_type
{
  unsigned char	type;
  char		*str;
  t_uint	size;
};

extern struct s_type	g_type[9];

struct		s_direction
{
  unsigned char	direction;
  int		(*s_a)(t_user_list *user, t_utils *utils, t_uint *size);
  int		(*string)(t_user_list *user, t_utils *utils, char *str);
};

# define RIGHT_CELL(x, i) ((((x) + (i)) + MAP->width) % MAP->width)
# define LEFT_CELL(x, i) ((((x) - (i)) + MAP->width) % MAP->width)
# define TOP_CELL(y, i) ((((y) - (i)) + MAP->height) % MAP->height)
# define BOTTOM_CELL(y, i) ((((y) + (i)) + MAP->height) % MAP->height)

int	append_cell_content(t_cell *cell, char *str, t_user_list *user);
int	append_cell_object(t_cell *cell, char *str);
int	append_element(unsigned char type, char *str, t_uint max);
int	append_cell_player(t_cell *cell, char *str, t_user_list *user);

#endif		/* !SERVER_COMMAND_WATCH_H_ */
