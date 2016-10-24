##
## Makefile for zappy in /home/budelo_s/rendu/zappy
## 
## Made by stephane budelot
## Login   <budelo_s@epitech.net>
## 
## Started on  Fri Jun 27 10:52:36 2014 stephane budelot
## Last update Sun Jul 13 21:52:29 2014 Nathan BIGAIGNON
##

NAME	=	client

SRCS	=	main_client.c		\
		all_init.c		\
		client.c		\
		client_traitement.c	\
		broadcast_ia.c		\
		broadcast_ia2.c		\
		ia.c			\
		search_rock.c		\
		survive.c		\
		elevation.c		\
		map_fork_inv.c		\
		communication_ia.c	\
		tri_recep_server.c	\
		fill_in_map.c		\
		tri_broadcast.c		\
		algo_move.c		\
		fonct_move.c		\
		error.c			\
		t_str_list.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-ansi -pedantic -W -Wall -Wextra

WHITE	=       \033[0m
RED	=       \033[1;31m

all     :       $(NAME)

$(NAME):	$(OBJS)
		gcc -o $(NAME) $(OBJS)
		@echo -e "$(RED)> IA compiled$(WHITE)"

clean:
		rm -rf $(OBJS)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
