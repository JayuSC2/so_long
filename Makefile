NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX = -lmlx -lX11 -lXext
SRC = src/so_long.c \
src/check_map.c \
src/read_map.c \
src/create_map.c \
src/create_game.c \
src/render_map.c \
src/utils.c \
src/movement.c \
src/handle_input.c \
src/init_game.c

OBJS = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	@$(MAKE) -s -C ./libft
	@$(CC) $(CFLAGS) $(MLX) $(OBJS) ./libft/libft.a -o $(NAME)
	@echo "Program ready!"

clean: 
	@$(MAKE) -s -C ./libft fclean
	@$(RM) $(OBJS)
	@echo "Program cleaned successfully!"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
