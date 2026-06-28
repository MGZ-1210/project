##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## compile project
##

CC	=	clang

NAME	=	mysh

SRC_MAIN	=	src/main.c

SRC_FILES	=	src/my_strcpy.c\
				src/my_strlen.c\
				src/my_strdup.c\
				src/my_strchr.c\
				src/my_strcmp.c\
				src/my_strncmp.c\
				src/linked_list.c\
				src/path_env.c\
				src/count_words.c

OBJ	=	$(SRC_FILES:.c=.o)\
		$(SRC_MAIN:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(SRC_MAIN) $(SRC_FILES) -o $(NAME) -g3

clean:
	rm -f $(OBJ)
	rm -f src/.c~
	rm -f include/.h~
	rm -f Makefile~

fclean:	clean
	rm -f $(NAME)

re:	fclean all
