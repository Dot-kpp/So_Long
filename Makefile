TARGET = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = ./mlx

SRCS = 	so_long.c

OBJ = $(SRCS:%c=%o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@


all:
	@$(CC) -lmlx -framework OpenGL -framework AppKit $(SRCS)
	@echo ""
	@echo "Your shit is compiled"
	@echo ""
	@echo "ᕙ( ͡❛ ͜ʖ ͡❛)ᕗ"
	@echo ""

run:$(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LIB) -framework OpenGL -framework AppKit -o $(TARGET)

frustration:
	@echo "FUUUCK"

clean:
	@rm -rf $(OBJ) $(BONUSOBJ)

fclean: clean
	@rm -rf $(TARGET) *.out
	@echo ""
	@echo "Your shit is clean af!"
	@echo ""
	@echo "(👍 ͡❛ ͜ʖ ͡❛)👍"
	@echo ""

re:	fclean all