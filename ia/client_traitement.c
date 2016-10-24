/*
** client_traitement.c for  in /home/kta-strof/Rendu/zappy_local
** 
** Made by 
** Login   <langro_s@epitech.eu>
** 
** Started on  Thu Jun 26 04:43:22 2014 
** Last update Sun Jul 13 12:01:03 2014 stephane budelot
*/

#include	<stdlib.h>
#include	<string.h>

#include	"error.h"

static int	if_argc_4(char **argv, int i)
{
  while (argv[3][i])
    {
      if (!((argv[3][i] >= 48 && argv[3][i] <= 57) || argv[3][i] == 46))
	return (raise_error("Port must be an int only.",
			    __FUNCTION__, EXIT_FAILURE));
      i++;
    }
  return (0);
}

int		verif_cmd(int argc, char **argv)
{
  int	i;

  i = 0;
  if (!(argc > 2 && argc < 5))
    return (raise_error("Usage : ./client team_name port [host].",
			__FUNCTION__, EXIT_FAILURE));
  if (strcmp(argv[1], "") == 0)
    return (raise_error("Team name must be a non empty string.",
			__FUNCTION__, EXIT_FAILURE));
  while (argv[2][i])
    {
      if (!(argv[2][i] >= 48 && argv[2][i] <= 57))
	return (raise_error("Port must be an int only.",
			    __FUNCTION__, EXIT_FAILURE));
      i++;
    }
  i = 0;
  if (argc == 4)
    if (if_argc_4(argv, i) == -1)
      return (-1);
  return (0);
}
