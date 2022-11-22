##
## EPITECH PROJECT, 2022
## makefile bsq
## File description:
## makefile bsq
##

SRC =	src/load_2d_arr_from_file.c	\
		src/my_strlen.c	\
		src/load_file_in_str.c	\
		src/is_square_of_size.c	\
		src/my_getnbr.c	\
		src/find_info.c	\
		src/check_square.c	\
		src/generating_maps.c	\


OBJ = $(SRC:.c=.o)

CFLAGS = -I include/

NAME = bsq

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -g

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f \#*\#
	rm -f vgcore.*

fclean: clean
	rm -f $(NAME)

re: 	fclean all

test_run:	$(OBJ)
	gcc -o test_units $(SRC) tests/*.c -I include/ --coverage -lcriterion
	-./test_units
	gcovr --exclude tests/
	rm *.gcno
	rm *.gcda
	rm test_units

run:
	gcc main.c -L. -lmy -I include/ -o run
	-./run

debug:	$(OBJ)
	gcc main.c $(OBJ) -I include/ -g -o debug
	valgrind ./debug

.PHONY: lib re all test_run clean fclean test_run run
