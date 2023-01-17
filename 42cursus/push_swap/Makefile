NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS :=
SRCS += main.c

LIBFT = ./libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $@ $^ -Llibft -lft
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