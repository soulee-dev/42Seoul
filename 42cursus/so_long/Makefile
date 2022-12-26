SOURCES = so_long.c
OBJECTS = $(SOURCES:.c=.o)
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): so_long.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	
fclean: clean
	rm -f so_long libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re