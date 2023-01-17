NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS :=
SRCS += so_long.c
SRCS += map.c
SRCS += so_long_utils2.c
SRCS += check_valid.c
SRCS += so_long_utils.c
SRCS += get_next_line.c
SRCS += get_next_line_utils.c

LIBFT = ./libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $@ $^ -Llibft -lft -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
	@echo Compile Complete! 🥳
	
%.o: %.c
	$(CC) -c $(CFLAGS) $?

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re