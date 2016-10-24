/*
** server_init_user_list.c for zappy in /home/epi/repositories/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Wed Jun 25 13:30:52 2014 Nathan BIGAIGNON
** Last update Wed Jun 25 16:43:50 2014 Nathan BIGAIGNON
*/

#include <stdlib.h>
#include "server_init_user_list.h"
#include "error.h"

int	init_user_list(t_utils *utils)
{
  if ((utils->user = malloc(sizeof(t_user_desc))) == NULL)
    return (std_raise_error(__FUNCTION__, EXIT_FAILURE));
  utils->user->head = NULL;
  utils->user->tail = NULL;
  utils->user->size = 0;
  return (EXIT_SUCCESS);
}
