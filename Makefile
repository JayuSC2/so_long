NAME = so_long.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
MLX = mlx/makefile.gen
INC = -I ./libft -I ./mlx
LIB = -L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
SRC = src/so_long.c \
src/read_map.c \
src/check_map.c \
src/render_map.c \
src/utils.c

OBJS = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	@$(MAKE) -s -C ./libft
	@$(CC) $(CFLAGS) $(INC) $(LIB) $(MLX) $(OBJS) ./libft/libft.a -o $(NAME)
	@echo "Program ready!"

clean: 
	@$(MAKE) -s -C ./libft fclean
	@$(RM) $(OBJS)
	@echo "Program cleaned successfully!"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
