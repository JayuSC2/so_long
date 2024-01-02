NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

HEADERS = libft_h

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJS) $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re