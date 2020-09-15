##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	?=	gcc

SRC	=	src/game/display/print_next.c			\
		src/game/display/print_map.c			\
		src/game/display/print_score.c			\
		src/game/display/print_title.c			\
								\
		src/game/logic/generate_tetrimino.c		\
		src/game/logic/put_tetrimino_utils.c		\
		src/game/logic/put_tetrimino.c			\
		src/game/logic/rotate.c				\
		src/game/logic/update_pos.c			\
		src/game/logic/check_map.c			\
								\
		src/game/check_end.c				\
		src/game/loop.c					\
		src/game/end.c					\
		src/game/pause_loop.c				\
		src/game/play_tetris.c				\
								\
		src/initialization/check_wrong_tetriminos.c	\
		src/initialization/init_game_map.c		\
		src/initialization/init_game_struct.c		\
		src/initialization/init_game_window.c		\
		src/initialization/init_game.c			\
		src/initialization/init_keybind.c		\
		src/initialization/init_keys_struct.c		\
		src/initialization/init_score_struct.c		\
		src/initialization/init_tetriminos.c		\
		src/initialization/init_tetriminos_utils.c	\
		src/initialization/my_custom_str_isnum.c	\
		src/initialization/press_any_key.c		\
		src/initialization/set_key_next.c		\
		src/initialization/transform_in_map.c		\
								\
		src/my_utils/malloc_2d_array.c			\
		src/my_utils/my_strcmp.c			\
		src/my_utils/my_strlen.c			\
		src/my_utils/my_atoi.c				\
		src/my_utils/my_putchar.c			\
		src/my_utils/my_putstr.c			\
		src/my_utils/my_put_nbr.c			\
		src/my_utils/my_pow.c				\
		src/my_utils/my_strdup.c			\
								\
		src/main.c					\
		src/print_debug_mode.c				\
								\


OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

CFLAGS	+=	-g -W -Wall

CPPFLAGS	+=	-I include/ -I include/initialization/

LDFLAGS	=	-lncurses

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
