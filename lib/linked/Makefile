##
## EPITECH PROJECT, 2020
## liblinked
## File description:
## Makefile
##

SRC			=	list/ll_add.c	\
				list/ll_append.c	\
				list/ll_destroy.c	\
				list/ll_get.c	\
				list/ll_len.c	\
				list/ll_pop.c	\
				list/ll_prepend.c	\
				list/ll_shift.c	\
				list/ll_remove.c	\
				list/ll_swap.c	\
				dict/dict_add.c	\
				dict/dict_destroy.c	\
				dict/dict_get.c	\
				dict/dict_remove.c	\
				dict/dict_swap.c	\
				dict/dict_len.c	\

CFLAGS		+=	-W -Wall -Wextra -pedantic
CFLAGS		+=	-I../../include

OBJ 		=	$(SRC:.c=.o)

NAME		=	liblinked.a

all: 	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) ../$(NAME)
