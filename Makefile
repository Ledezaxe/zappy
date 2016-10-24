##
## Makefile for zappy in /home/epi/repositories/PSU_2013_zappy
## 
## Made by Nathan BIGAIGNON
## Login   <bigaig_n@epitech.eu>
## 
## Started on  Sun Jul 13 21:34:26 2014 Nathan BIGAIGNON
## Last update Sun Jul 13 22:05:14 2014 Nathan BIGAIGNON
##

NAME		=	zappy

all:		$(NAME)

$(NAME):
			make -C server all
			make -C ia all

clean:
			make -C server clean
			make -C ia clean

fclean:		clean
			make -C server fclean
			make -C ia fclean

re:		fclean all

.PHONY:		all clean fclean re
