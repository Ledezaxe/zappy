##
## Makefile for zappy in /home/epi/repositories/zappy
## 
## Made by Nathan BIGAIGNON
## Login   <bigaig_n@epitech.eu>
## 
## Started on  Tue Jun 24 15:30:57 2014 Nathan BIGAIGNON
## Last update Sun Jul 13 21:27:54 2014 Nathan BIGAIGNON
##

NAME		=		server

SRCS		=		main.c \
				error.c \
				t_user_list.c \
				t_server_options.c \
				server_set_options.c \
				server_set_teams.c \
				server_check_args.c \
				server_init_container.c \
				server_init_argument.c \
				server_init_socket.c \
				server_init_map.c \
				server_init_object.c \
				server_init_user_list.c \
				server_destroy_container.c \
				server_destroy_argument.c \
				server_destroy_socket.c \
				server_destroy_map.c \
				server_destroy_user_list.c \
				server_add_player.c \
				server_user_inventory.c \
				server_command_watch.c \
				server_command_watch_size.c \
				server_command_watch_up.c \
				server_command_watch_down.c \
				server_command_watch_left.c \
				server_command_watch_right.c \
				server_conf_socket.c \
				server_loop.c \
				server_commands_client.c \
				server_clients_controller.c \
				server_command_inventory.c \
				server_command_broadcast.c \
				server_command_broadcast_distance.c \
				server_command_broadcast_position.c \
				server_command_left.c \
				server_command_right.c \
				server_command_grab.c \
				server_command_grab_object1.c \
				server_command_grab_object2.c \
				server_command_drop.c \
				server_command_drop_object1.c \
				server_command_drop_object2.c \
				server_error.c \
				server_send_msg.c \
				server_command_forward.c \
				server_command_forward_move.c \
				server_command_expulse.c \
				server_command_incantation.c \
				server_command_incantation_evolve.c \
				server_search_func.c \
				server_command_gui.c \
				server_command_gui2.c \
				server_command_incantation_msg.c \
				server_time_controller.c \
				server_command_connect_nbr.c \
				server_random_resources.c \
				server_random_resources2.c \
				t_players_ptr.c \
				t_monitors.c \
				t_egg.c \
				server_time_manager.c \
				server_destroy_monitor.c \
				server_destroy_egg.c \
				server_command_fork.c \
				server_time_manager2.c \
				server_store_scheduled_cmd.c \
				server_stdin_monitoring.c \
				server_add_egg_player.c \
				server_destroy_egg_player.c

OBJS		=		$(SRCS:.c=.o)

CFLAGS		=		-W -Wall -Wextra

CFLAGS		+=		-ansi -pedantic

CC		=		gcc

RM		=		rm -rf

all:		$(NAME)

$(NAME):		$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
