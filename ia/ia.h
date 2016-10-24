/*
** ia.h for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Wed Jun 25 15:46:47 2014 stephane budelot
** Last update Sun Jul 13 13:10:36 2014 stephane budelot
*/

#ifndef		IA_H_
# define	IA_H_

#include	<sys/select.h>
#include	<sys/time.h>
#include	<sys/types.h>
#include	<unistd.h>

struct s_type
{
  char	name[15];
  int   type;
};

extern struct s_type g_type[8];

struct		s_lvlup
{
  int		lvl;
  int		lin;
  int		der;
  int		sib;
  int		men;
  int		phi;
  int		thy;
  int		nbr_j;
};

extern struct s_lvlup g_stone[7];

typedef struct	s_ia
{
  int		lvl;
  int		life;

  int		cmd_v;
  int		cmd_i;

  char		broadcast[50];
  int		broadcast_pos;
  int		elev;
  int		nbr_here;

  int		lvl8[87][7];

  int		tt_linemate;
  int		tt_deraumere;
  int		tt_sibur;
  int		tt_mendiane;
  int		tt_phiras;
  int		tt_thystame;

  int		fd;

  int		dead;
}		t_ia;

int             new_ia(int fd);
int		start_elevation(t_ia *ia);

void            init_ia(t_ia *ia);
void            init_struct_map(t_ia *m);

int             search_stone(t_ia *ia);
int             all_stone(t_ia *ia);
void            take_that_stone(char *stone, t_ia *ia);
void            take_that_stone(char *stone, t_ia *ia);

int             move_to_elevation(t_ia *ia);
int		pose_stone_to_up(t_ia *ia);
int		take_all_stone(t_ia *ia);

int             survive(t_ia *ia);

void            voir_inventaire(t_ia *ia);
int             inventaire(t_ia *ia);
int		do_fork(t_ia *ia);
int		see_map(t_ia *ia);

int             recep_serv(int sc, t_ia *ia);
int             send_serv(int sc, char *str);
int             communication_ia(t_ia *ia);

int             broadcast_cancel(int fd, t_ia *ia);
int             broadcast_for_elevation(int fd, t_ia *ia);
int             broadcast_here(int fd, t_ia *ia);
int             broadcast_elevation(int fd);
int             broadcast_elevation_end(int fd, t_ia *ia);
int             broadcast_enough_people(int fd, t_ia *ia);

int		tri_info(t_ia *ia, char *str);
void            recep_inventaire(char *str, t_ia *ia);
void            new_lvl(char *str, t_ia *ia);
void            team_slot_empty(char *str);

int		cut_string(t_ia *ia, char *str);
int             check_square(t_ia *m, char *str, int i);

void            broadcast_txt(t_ia *ia, char *str);

int             move_to_evolve(t_ia *ia, int obj);
int		move_to_take(t_ia *m, int obj, int i, int x);
int             move_in_diag_to_take(t_ia *m, int dg, int x);
int		move_x(t_ia *m, int i);

int             move_right(int fd);
int             move_left(int fd);
int             move_front(int fd);
int		move_take(int i, int fd, t_ia *ia);
int             move_pose(int i, int fd);

# endif		/* !IA_H_ */
