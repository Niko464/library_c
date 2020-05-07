##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## This is my makefile
##


RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
WHITE=\033[1;37m
NC=\033[0m

SRC_DIR	=		src

MAIN 	=		$(SRC_DIR)/main.c

SRC		=		$(SRC_DIR)/project.c

SRC_TESTS=		tests/libmy_tests.c

DIR_INCLUDE =	include
NAME_LIB =		libmy.a



CFLAGS		=	-Iinclude -Wall -Wextra -pedantic -Wpedantic
LFLAGS		=	-L. -lmy
DIR_LIB =		lib/my
NAME	=		PROJECT_NAME
NAME_TESTS	=	unit_tests

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)
OBJ_NO_MAIN =	$(SRC:.c=.o)
OBJ_TESTS =		$(SRC_TESTS:.c=.o)


all:	$(NAME)

$(NAME):		make_lib compil

make_lib:
	@cd $(DIR_LIB) && make

compil:		$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)


tests_run:	$(OBJ_NO_MAIN) $(OBJ_TESTS)
	@gcc -o $(NAME_TESTS) $(OBJ_NO_MAIN) $(OBJ_TESTS) $(CFLAGS) $(LFLAGS) --coverage -lcriterion;
	./unit_tests;

debug: $(OBJ)
	@gcc -g3 $(OBJ) $(CFLAGS) $(LFLAGS)

clean:
	@echo -e "${GREEN}[CLEAN] ${WHITE}Removing ${BLUE}project components${WHITE}...${NC}"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo -e "${GREEN}[FCLEAN] ${WHITE}Removing ${BLUE}${NAME_LIB}${WHITE}...${NC}"
	@rm -f $(NAME_LIB)
	@cd $(DIR_LIB) && make fclean

re: fclean all

.PHONY: re