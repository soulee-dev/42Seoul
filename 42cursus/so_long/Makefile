NAME = so_long
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS :=
SRCS += so_long.c
SRCS += map.c
SRCS += move.c
SRCS += check_valid.c
SRCS += so_long_utils.c
SRCS += get_next_line.c
SRCS += get_next_line_utils.c

all: $(LIBFT) $(NAME)

$(NAME):
	$(CC) $(SRCS) $(LIBFT) $(CFLAGS) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -g3

$(LIBFT):
	make -C ./libft

clean:
	make clean -C ./libft

fclean:
	make fclean -C ./libft
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus libft clean fclean re