/*
** server_set_teams.c for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Mon Jun 23 14:16:47 2014 Max Prudhomme
** Last update Fri Jul 11 20:07:58 2014 Nathan BIGAIGNON
*/

#include <string.h>
#include <stdlib.h>
#include "server_set_teams.h"
#include "error.h"

void	set_team_name(char *str, t_server_options *options)
{
  (void)str;
  options->nb_team++;
}

int		create_table(t_server_options *options, int index_team, char **av)
{
  t_uint	i;

  options->team_name = malloc(sizeof(char **) * options->nb_team + 1);
  if (options->team_name == NULL)
    return (std_raise_error(__FUNCTION__, -1));
  i = 0;
  while (i < options->nb_team)
    {
      options->team_name[i] = malloc(sizeof(char *) * strlen(av[index_team]));
      if (options->team_name[i] == NULL)
	return (std_raise_error(__FUNCTION__, -1));
      strcpy(options->team_name[i], av[index_team]);
      if (options->team_name[i] == NULL)
	return (std_raise_error(__FUNCTION__, -1));
      ++index_team;
      ++i;
    }
  return (0);
}

int		validation_teams(char **teams, t_uint nb_team)
{
  t_uint	i;
  t_uint	y;

  i = 0;
  while (i < (nb_team - 1))
    {
      y = 0;
      while (y < nb_team)
	{
	  if (i != y)
	    {
	      if (is_identic(teams[i], teams[y]) == 0)
		return (raise_error("Same team name", __FUNCTION__, -1));
	    }
	  ++y;
	}
      ++i;
    }
  return (0);
}

int	is_identic(char *str1, char *str2)
{
  char	*find;

  if (strlen(str1) != strlen(str2))
    return (-1);
  find = strstr(str2, str1);
  if (find == NULL)
    return (-1);
  if (find == str1)
    return (-1);
  return (0);
}
