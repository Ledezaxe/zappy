/*
** server_store_scheduled_cmd.c for zappy in /home/epi/repositories/restart_zappy/zappy
** 
** Made by Nathan BIGAIGNON
** Login   <bigaig_n@epitech.eu>
** 
** Started on  Sat Jul 12 18:22:53 2014 Nathan BIGAIGNON
** Last update Sun Jul 13 13:25:10 2014 Max Prudhomme
*/

#include <string.h>
#include "server_store_scheduled_cmd.h"
#include "server_command_incantation.h"
#include "server_command_fork.h"
#include "server_commands_client.h"

void	store_scheduled_cmd(t_utils *utils, t_user_list *p, int index, int i)
{
  if (strcmp(SOCKET->buffer, "fork\n") == 0)
    {
      fork_msg_start(utils, p);
      p->action[index].start = g_ia[i].time;
      p->action[index].fct = g_ia[i].fct;
      memset(p->action[index].buff, 0, 255);
      strcpy(p->action[index].buff, SOCKET->buffer);
    }
  else
    {
      if (strcmp(SOCKET->buffer, "incantation\n") == 0)
	incantation_msg_start(utils, p);
      p->action[index].start = g_ia[i].time;
      p->action[index].fct = g_ia[i].fct;
      memset(p->action[index].buff, 0, 255);
      strcpy(p->action[index].buff, SOCKET->buffer);
    }
}
