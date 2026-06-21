CC	=	clang

NAME	=	shell

SRC_MAIN	=	main.c
SRC_FILES	=	my_strcpy.c\
				my_strlen.c\
				my_strdup.c\
				my_strchr.c\
				my_strcmp.c\
				my_strncmp.c\
				code.c\
				count_words.c

OBJ	=	$(SRC_FILES:.c=.o)\
		$(SRC_MAIN:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(SRC_MAIN) $(SRC_FILES) -o $(NAME) -g3

clean:
	rm -f $(OBJ)
	rm -f .c~
	rm -f .h~
	rm -f Makefile~

fclean:	clean
	rm -f $(NAME)

re:	fclean all
