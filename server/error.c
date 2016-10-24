/*
** error.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Thu Jun 19 15:06:06 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 21:09:43 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "error.h"

int	raise_error(const char *msg, const char *function, int retval)
{
  if ((write(2, msg, strlen(msg))) == -1)
    return (std_raise_error(__FUNCTION__, -1));
  if ((write(2, " in : ", 6)) == -1)
    return (std_raise_error(__FUNCTION__, -1));
  if ((write(2, function, strlen(function))) == -1)
    return (std_raise_error(__FUNCTION__, -1));
  if ((write(2, "\n", 1)) == -1)
    return (std_raise_error(__FUNCTION__, -1));
  return (retval);
}

int	std_raise_error(const char *function, int retval)
{
  perror(function);
  return (retval);
}
