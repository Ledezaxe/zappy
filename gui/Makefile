##
## Makefile for  in /home/ledezaxe/test_sfml
## 
## Made by Quentin Rouanet
## Login   <ledezaxe@epitech.net>
## 
## Started on  Mon Jun 23 18:09:54 2014 Quentin Rouanet
## Last update Sun Jul 13 22:04:38 2014 Nathan BIGAIGNON
##

NAME	= GUI

SRCS	= main.cpp \
	  carte.cpp \
	  cellule.cpp \
	  network.cpp

OBJ	= $(SRCS:.cpp=.o)

CC	= g++

RM	= rm -f

ECHO	= @echo -e

CPPFLAGS	+= -W -Wall -Wextra
CPPFLAGS	+= -Werror
CPPFLAGS	+= -std=c++11

LIBSFML		= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

all	: $(NAME)

$(NAME)	: $(OBJ)
	  $(CC) -o $(NAME) $(OBJ) $(LIBSFML)
	  $(ECHO) '\033[0;32m> Compiled\033[0m'

clean	:
	  $(RM) $(OBJ)
	  $(RM) *~
	  $(RM) \#*#
	  $(ECHO) '\033[0;31m> Directory cleaned\033[0m'

fclean	: clean
	  $(RM) $(NAME)
	  $(ECHO) '\033[0;31m> Remove executable\033[0m'

re	: fclean all

.PHONY	: all clean fclean re