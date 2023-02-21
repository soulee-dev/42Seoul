NAME = push_swap
NAME_BONUS = checker
CC = cc
# CFLAGS = -Wall -Wextra -Werror

SRCS :=
SRCS += push_swap.c
SRCS += push_swap_utils1.c
SRCS += push_swap_utils2.c
SRCS += instructions1.c
SRCS += instructions2.c
SRCS += list.c
SRCS += greedy1.c
SRCS += greedy2.c
SRCS += hard_sort.c

SRCS_BONUS :=
SRCS_BONUS += push_swap_bonus.c
SRCS_BONUS += get_next_line_bonus.c
SRCS_BONUS += get_next_line_utils_bonus.c

LIBFT = ./libft/libft.a

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRCS.c=.o)

all: $(LIBFT) $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $@ $^ -Llibft -lft -g3
	@echo Compile Complete! 🥳

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) -o $@ $^ -Llibft -lft -g3
	@echo Compile Complete! 🥳

%.o: %.c
	$(CC) -c $(CFLAGS) $? -g3

$(LIBFT):
	make -C ./libft bonus

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C ./libft

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME) $(NAME_BONUS)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re