NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBX = /library/mlx/libmlx.a 

LIBFT = /library/libft/libft.a

SRCS = 	so_long.c init_data.c errors.c map.c parsing.c render.c moves.c free_dbl_arr.c events.c savior.c

OBJ = $(SRCS:%c=%o)

all: $(LIBFT) $(NAME)

$(LIBFT) :
	@echo "Your libft is compiling"
	@echo ""
	@$(MAKE) -C libft
	@echo ""


$(NAME) : src/so_long.o src/parsing.o src/errors.o src/init_data.o src/map.o src/render.o src/free_dbl_arr.o src/savior.o src/moves.o src/events.o include/so_long.h
	@echo "Compiling so_long"
	@echo ""
	@$(CC) src/so_long.o src/parsing.o src/errors.o src/map.o src/init_data.o src/free_dbl_arr.o src/savior.o src/render.o src/moves.o src/events.o libft/libft.a -lmlx -framework OpenGL -framework AppKit -o so_long
	@echo ""
	@echo "Your shit is compiled"
	@echo ""

frustration:
	@echo "FUUUCK"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf *.out *.exe so_long ./src/*.o ./libft/src/*.o 
	@echo ""
	@echo "Your shit is clean af!"
	@echo ""
	@echo "(👍 ͡❛ ͜ʖ ͡❛)👍"
	@echo ""

re:	fclean all