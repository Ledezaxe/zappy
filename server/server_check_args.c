/*
** server_check_args.c for zappy in /home/zheness/repositories/zappy
** 
** Made by Max Prudhomme
** Login   <prudho_m@epitech.net>
** 
** Started on  Thu Jun 19 15:48:29 2014 Max Prudhomme
** Last update Wed Jun 25 18:54:13 2014 Max Prudhomme
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "server_check_args.h"
#include "error.h"
#include "server_set_options.h"
#include "server_set_teams.h"

static struct s_server_section g_sections[7] = {
  {"-p", NUM_PORT, set_num_port},
  {"-x", MAP_WIDTH, set_map_width},
  {"-y", MAP_HEIGHT, set_map_height},
  {"-n", TEAM_NAME, set_team_name},
  {"-c", NUM_CLIENT, set_num_client},
  {"-t", TIME_EXEC, set_time_exec},
  {"", NONE, set_num_port}
};

int		check_option_exists(char *str, unsigned char *section)
{
  unsigned char	i;

  if (strlen(str) == 2)
    {
      i = 0;
      while (i < 7)
	{
	  if (strstr(g_sections[i].name, str) != NULL)
	    {
	      *section = g_sections[i].type;
	      return (1);
	    }
	  ++i;
	}
    }
  return (0);
}

int	check_index_team(char section, int *index_team, char i)
{
  if (section == TEAM_NAME)
    {
      if (*index_team == 0)
	*index_team = i;
      else
	return (raise_error("Teams already added", __FUNCTION__, -1));
    }
  return (0);
}

int		start_loop_checking(int ac, char **av, t_server_options *options)
{
  unsigned char	section;
  unsigned char	i;
  int		index_team;

  section = NONE;
  i = 1;
  index_team = 0;
  while (i < ac)
    {
      if (check_option_exists(av[i], &section) == 0)
	{
	  if (section == NONE)
	    return (raise_error("Invalid argument", __FUNCTION__, -1));
	  g_sections[section].fct(av[i], options);
	}
      else
	if (check_index_team(section, &index_team, i) == -1)
	  return (-1);
      ++i;
    }
  return (index_team);
}

int	start_checking(int ac, char **av, t_server_options *options)
{
  int	index_team;

  init_struct(options);
  if ((index_team = start_loop_checking(ac, av, options)) == -1)
    return (-1);
  if (index_team == 0)
    return (raise_error("No team added", __FUNCTION__, -1));
  if (end_checking(options, index_team + 1, av) == -1)
    return (-1);
  return (0);
}

int	end_checking(t_server_options *options, int index_team, char **av)
{
  if (options->num_port <= 0)
    return (raise_error("Port invalid", __FUNCTION__, -1));
  if (options->map_width <= 0)
    return (raise_error("Map width invalid", __FUNCTION__, -1));
  if (options->map_height <= 0)
    return (raise_error("Map height invalid", __FUNCTION__, -1));
  if (options->num_client <= 0)
    options->num_client = 1;
  if (options->time_exec <= 0)
    options->time_exec = 100;
  if (create_table(options, index_team, av) == -1)
    return (-1);
  if (validation_teams(options->team_name, options->nb_team) == -1)
    return (-1);
  return (0);
}
