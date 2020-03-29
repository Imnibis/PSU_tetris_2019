##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Builds the project
##

CC	=	gcc

RM	=	rm -f

MK	=	make --no-print-directory

SRC		=	src/main.c $(DISPLAY) $(GAMEPLAY) $(SETTINGS) $(TETRIMINOS) $(UTIL)

DISPLAY	=	src/display/debug.c	\
			src/display/color.c	\
			src/display/title.c	\
			src/display/score.c	\
			src/display/usage.c	\
			src/display/map.c	\
			src/display/tetriminos.c	\
			src/display/windows.c	\

GAMEPLAY	=	src/gameplay/start.c	\
				src/gameplay/loop.c	\
				src/gameplay/time.c	\
				src/gameplay/input.c	\

SETTINGS	=	src/settings/arguments.c	\
				src/settings/variable.c	\

TETRIMINOS	=	src/tetriminos/parse.c	\
				src/tetriminos/sort.c	\
				src/tetriminos/put_in_map.c	\
				src/tetriminos/move.c	\
				src/tetriminos/generate.c	\

UTIL		=	src/util/memory_management.c	\
				src/util/setup_term.c	\

OBJ		=	$(SRC:.c=.o)

NAME		=	tetris

CFLAGS		+=	-W -Wall -Wextra -pedantic
CFLAGS		+=	-I./include -L./lib

LIBTOOLS	=	-l tools -l ncurses

LIBLINKED	=	-l linked

LIBJSON		=	-l json

LIBGAME		=	-l game	\
				-l csfml-graphics	\
				-l csfml-audio	\
				-l csfml-system	\
				-l csfml-window	\
				-l csfml-network

$(OBJDIR)%.o:	%.c
		@$(CC) $(CFLAGS) -o $@ -c $<
		@if test -s $*.c; then \
		echo -e "\033[01m\033[35m Compiling \033[00m\
		\033[36m$(SRCPATH)$*.c\033[032m  [OK]\033[00m";\
		else \
		echo -e "\033[01m\033[33m Compiling \033[00m\
		\033[36m$(SRCPATH)$*.c\033[00m\  [Error]"; fi

all:		linked tools $(NAME)

$(NAME):	$(OBJ)
		@echo -e "\033[01m\033[31mBuilding...\033[00m"
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
		@echo -e "\033[01m\033[32mCompilation done: ${NAME}\033[00m"

tools:
		$(eval CFLAGS += $(LIBTOOLS))
		@$(MK) -C lib/tools
game:
		$(eval CFLAGS += $(LIBGAME))
		@$(MK) -C lib/game
linked:
		$(eval CFLAGS += $(LIBLINKED))
		@$(MK) -C lib/linked
json:
		$(eval CFLAGS += $(LIBJSON))
		@$(MK) -C lib/json

tools_clean:
		@echo -e "\033[01m\033[31mCleaning libtools...\033[00m"
		@$(MK) -C lib/tools clean
game_clean:
		@echo -e "\033[01m\033[31mCleaning libgame...\033[00m"
		@$(MK) -C lib/game clean
linked_clean:
		@echo -e "\033[01m\033[31mCleaning liblinked...\033[00m"
		@$(MK) -C lib/linked clean
json_clean:
		@echo -e "\033[01m\033[31mCleaning libjson...\033[00m"
		@$(MK) -C lib/json clean

tools_fclean:
		@$(MK) -C lib/tools fclean
game_fclean:
		@$(MK) -C lib/game fclean
linked_fclean:
		@$(MK) -C lib/linked fclean
json_fclean:
		@$(MK) -C lib/json fclean

debug:	linked tools $(OBJ)
		@echo -e "\033[01m\033[31mBuilding...\033[00m"
		@$(CC) -g3 $(SRC) $(CFLAGS)
		@echo -e "\033[01m\033[32mCompilation done: a.out\033[00m"

clean:	linked_clean tools_clean
		@echo -e "\033[01m\033[31mCleaning objects...\033[00m"
		@$(RM) $(OBJ)

fclean:		clean linked_fclean tools_fclean
		@echo -e "\033[01m\033[31mCleaning binary...\033[00m"
		@$(RM) $(NAME)

re:		fclean all
