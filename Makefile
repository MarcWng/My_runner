##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	src/event.c	\
		src/secondary_functions.c	\
		src/main.c	\
		src/movement.c	\
		src/rat_hopper_sprite.c	\
		src/jump.c	\
		src/move_functions.c	\
		src/music.c	\
		src/map.c	\
		src/sprite.c	\
		src/hopper_movement.c	\
		src/hitbox.c

OBJ	=	$(SRC:.c=.o)

NOMAIN	=	src/event.c	\
		src/secondary_functions.c	\
		src/sprite_character.c	\
		src/rat.c	\
		src/jump.c	\
		src/move_functions.c	\
		src/music.c	\
		src/map.c

NAME	=	my_runner

CRITNAME =	unit_test

CPPFLAGS =	-I ./include

TEST	=	./tests/test.c

LIB	=	-L ./lib/my/ -lmy

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

TEMP     =	*.gcno	\
		*.gcda

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		make -C ./lib/my/
		gcc $(LIB) -o $(NAME) $(SRC) $(CSFML) $(LIB) $(CPPFLAGS)

test_run:
	gcc -o $(CRITNAME) $(NOMAIN) $(TEST) $(LIB) --coverage -lcriterion $(CSFML) $(CPPFLAGS)
	./unit_test

clean	:
		rm -f $(OBJ)
		rm -f $(TEMP)
		make clean -C ./lib/my/

fclean	:	clean
		rm -f $(NAME) $(CRITNAME)
		make fclean -C ./lib/my/

re	:	fclean all

.PHONY	:	all clean fclean re
