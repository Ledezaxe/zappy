/*
** error.h for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Thu Jun 19 15:06:14 2014 Nathan BIGAIGNON
** Last update Tue Jun 24 12:15:34 2014 Nathan BIGAIGNON
*/

#ifndef		ERROR_H_
# define	ERROR_H_

int	raise_error(const char *msg, const char *function, int reval);
int	std_raise_error(const char *function, int retval);

#endif		/* !ERROR_H_ */
