NAME = push_swap
CC = cc
# CFLAGS = -Wall -Wextra -Werror

SRCS :=
SRCS += push_swap.c
SRCS += error.c
SRCS += push_swap_utils.c
SRCS += instructions1.c
SRCS += instructions2.c
SRCS += list.c
SRCS += greedy1.c
SRCS += greedy2.c
SRCS += hard_sort.c

LIBFT = ./libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $@ $^ -Llibft -lft -fsanitize=address
	@echo Compile Complete! 🥳
	
%.o: %.c
	$(CC) -c $(CFLAGS) $? -g3 -fsanitize=address

$(LIBFT):
	make -C ./libft bonus

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