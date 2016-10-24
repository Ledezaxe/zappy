/*
** server_destroy_container.h for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Tue Jun 24 18:15:35 2014 Nathan BIGAIGNON
** Last update Fri Jul 11 20:32:28 2014 Nathan BIGAIGNON
*/

#ifndef		SERVER_DESTROY_CONTAINER_H_
# define	SERVER_DESTROY_CONTAINER_H_

# include	"t_utils.h"
# include	"t_monitors.h"

void	destroy_container(t_utils *utils);
void	destroy_monitor(t_monitors_desc *desc);
void	destroy_egg(t_egg_desc *desc);

#endif		/* !SERVER_DESTROY_CONTAINER_H_ */
