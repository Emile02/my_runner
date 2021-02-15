##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile for printf
##

NAME 	=		my_runner

SRC	=		src/convert_number_to_text.c	\
			src/destroy.c	\
			src/disp_score.c	\
			src/eventcall.c	\
			src/jump.c	\
			src/main.c	\
			src/menu.c	\
			src/move_background.c	\
			src/open_map.c	\
			src/pop_rock.c	\
			src/sound.c	\
			src/time.c


LDFLAGS	= -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

all : dolib $(NAME)

$(NAME):
		gcc -o $(NAME) -g -Wall -Wextra $(SRC) -lmy -L./lib/ $(LDFLAGS)

dolib:
		make -C ./lib/my

fclean:
		make fclean -C ./lib/my
		rm -f $(NAME)
		rm -f vgcore*

re:		fclean all

.PHONY: all fclean re