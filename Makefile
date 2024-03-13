##
## EPITECH PROJECT, 2022
## header
## File description:
## header
##

NAME			=		FASTAtools

TESTNAME		=		unit_tests

SRC				=		src/main.c					\
						src/getline_handler.c		\
						src/parmater_handling.c		\
						src/start_parting.c 		\
						src/option_1.c				\
						src/option_2.c				\
						src/option_3.c 				\
						src/option_4.c 				\
						src/option_5.c 				\
						src/letter_fonction.c		\

TESTSRC			=		src/letter_fonction.c		\
						tests/test_option_1.c		\
						tests/test_requierment.c	\
						requirement.c				\

WARNING			=		-W

INCLUDE_DIR 	=		-I ./include

CFLAGS			=       $(INCLUDE_DIR) $(WARNING)

TESTCFLAGS		=		-I./includes -Wall -Wextra -lcriterion --coverage

OBJ				=		$(SRC:.c=.o)

CC				=		gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		@rm -rf $(OBJ)
		@find -name "*.gcda" -delete -o -name "*.gcno" -delete

tests_run:	$(TESTOBJ)
		gcc -o $(TESTNAME) $(TESTSRC) $(TESTCFLAGS)
		./$(TESTNAME)

fclean:			clean
		@rm -rf $(NAME)
		@rm -rf $(TESTNAME)

re:		fclean 	$(NAME)
