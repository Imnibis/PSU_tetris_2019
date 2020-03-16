##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Builds the project
##

SRC		=	src/main.c	\

OBJ		=	$(SRC:.c=.o)

NAME		=	tetris

CFLAGS		+=	-W -Wall -Wextra -pedantic
CFLAGS		+=	-I./include -L./lib

LIBTOOLS	=	-l tools

LIBLINKED	=	-l linked

LIBJSON		=	-l json

LIBGAME		=	-l game	\
				-l csfml-graphics	\
				-l csfml-audio	\
				-l csfml-system	\
				-l csfml-window	\
				-l csfml-network

all:		linked tools $(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

tools:
		$(eval CFLAGS += $(LIBTOOLS))
		make -C lib/tools libtools.a
game:
		$(eval CFLAGS += $(LIBGAME))
		make -C lib/game libgame.a
linked:
		$(eval CFLAGS += $(LIBLINKED))
		make -C lib/linked liblinked.a
json:
		$(eval CFLAGS += $(LIBJSON))
		make -C lib/json libjson.a

tools_clean:
		make -C lib/tools clean
game_clean:
		make -C lib/game clean
linked_clean:
		make -C lib/linked clean
json_clean:
		make -C lib/json clean

tools_fclean:
		make -C lib/tools fclean
game_fclean:
		make -C lib/game fclean
linked_fclean:
		make -C lib/linked fclean
json_fclean:
		make -C lib/json fclean

debug:	linked tools $(OBJ)
		gcc -g3 $(SRC) $(CFLAGS)

clean:	linked_clean tools_clean 
		rm -f $(OBJ)

fclean:		clean linked_fclean tools_fclean 
		rm -f $(NAME)

re:		fclean all
