##
## EPITECH PROJECT, 2019
## Basic Makefile
## File description:
## Makefile
##

SRC		=	Component.cpp							\
			Factory.cpp								\
			Circuit.cpp								\
			Parser.cpp								\
			main.cpp

NAME	=	nanotekspice

OBJ		=	$(SRC:.cpp=.o)

CFLAGS	=	-W -Werror -Wextra -Wall -g3 -lm

CC = g++

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

mylib :
	make -C lib/

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
