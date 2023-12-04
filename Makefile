NAME = so_long.a
CC = CC
CFLAGS = -Wall -Wextra -Werror
MLX = mlx/makefile.gen
LFT = libft/libft.a
INC = -I ./inc -I ./libft -I ./mlx
LIB = -L ./libft -lft -L ./mlx -lmlx -lXext -lx11 -lm -lbsd
OBJ = $(patsubst src%, obj%, $(SRC.:.c=.o))
SRC = so_long.c \

all: $(MLX) $(LFT) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(MLX):
	@echo " [ .. ] | Compiling minilibx.."
	@make -C mlx
	@echo " [ OK ] | Minilibx ready!"

$(LFT):
	@echo " [ .. ] | Compiling libft"
	@make -C libft
	@echo " [ .. ] | Libft ready!"

clean:
	@make $@ -C libft
	@rm -f $(OBJ)
	@echo "object files removed."

fclean: clean
			@make $@ -C libft
			@rm -f $(NAME)
			@echo "binary file removed."

re: fclean all

.PHONY: all clean fclean re

