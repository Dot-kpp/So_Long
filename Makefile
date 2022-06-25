NAME = so_long.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = 	so_long.c main.c

OBJ = $(SRCS:%c=%o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

run:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


clean:
	rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	rm -f $(NAME) *.out

re:	fclean all