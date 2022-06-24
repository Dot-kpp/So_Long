NAME = so_long.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = 	so_long.c main.c

OBJ = $(SRCS:%c=%o)


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

run:$(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	$(CC) $(CFLAGS) $(NAME)

clean:
	rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	rm -f $(NAME) *.out

re:	fclean all