##
## EPITECH PROJECT, 2017
## NanoTekSpice
## File description:
## Makefile
##

SRC			=	main.cpp \
				classes/src/square.cpp

OBJ			=	$(SRC:.cpp=.o)

CXXFLAGS	=	-W -Wall -Wextra

NAME		=	square

CC			=	g++

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(CXXFLAGS) -o $(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			clean all
