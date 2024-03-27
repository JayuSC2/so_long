NAME = so_long.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = mlx/makefile.gen
LFT = libft/libft.a
INC = -I ./inc -I ./libft -I ./mlx
LIB = -L ./libft -lft -L ./mlx -lmlx -lXext -lx11 -lm -lbsd
SRC = main.c \
read_map.c \
check_map.c \
init_game.c \
render_map.c \
utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	@$(MAKE) -s -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)
	@echo "Program ready!"

clean: 
	@$(MAKE) -s -C ./libft fclean
	@$(RM) $(OBJS)
	@echo "Program cleaned successfully!"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
