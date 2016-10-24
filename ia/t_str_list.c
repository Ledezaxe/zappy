/*
** t_str_list.c for zappy in /home/budelo_s/rendu/zappy
** 
** Made by stephane budelot
** Login   <budelo_s@epitech.net>
** 
** Started on  Sat Jul 12 17:00:11 2014 stephane budelot
** Last update Sun Jul 13 14:41:41 2014 stephane budelot
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

#include	"t_str_list.h"
#include	"error.h"

void		free_str_list(t_str_list_desc *desc, char *buff)
{
  t_str_list	*tmp;
  t_str_list	*dup;

  tmp = desc->beg;
  while (tmp != NULL)
    {
      dup = tmp;
      free(tmp->str);
      tmp = tmp->next;
      free(dup);
    }
  free(buff);
}

void		init_str_list_desc(t_str_list_desc *desc)
{
  desc->end = NULL;
  desc->beg = NULL;
  desc->size_str = 0;
}

int		add_in_str_list(t_str_list_desc *desc, char *str)
{
  t_str_list	*elem;
  int		size;

  size = strlen(str);
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (std_raise_error(__FUNCTION__, -1));
  if ((elem->str = malloc(sizeof(char) * (size) + 1)) == NULL)
    return (-1);
  strcpy(elem->str, str);
  desc->size_str += size;
  if (desc->beg == NULL)
    {
      desc->end = elem;
      desc->beg = elem;
      elem->next = NULL;
    }
  else
    {
      desc->end->next = elem;
      elem->next = NULL;
      desc->end = elem;
    }
  return (0);
}

void		dump_str_list(t_str_list_desc *desc)
{
  t_str_list	*tmp;

  tmp = desc->beg;
  while (tmp != NULL)
    {
      printf("-->>%s<<--\n", tmp->str);
      tmp = tmp->next;
    }
}
