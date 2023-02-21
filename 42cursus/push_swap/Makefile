NAME = push_swap
NAME_BONUS = checker
CFLAGS = -Wall -Wextra -Werror

SRCS :=
SRCS += push_swap.c
SRCS += push_swap_utils1.c
SRCS += push_swap_utils2.c
SRCS += instructions1.c
SRCS += instructions2.c
SRCS += instructions3.c
SRCS += list.c
SRCS += greedy1.c
SRCS += greedy2.c
SRCS += hard_sort.c

SRCS_BONUS :=
SRCS_BONUS += push_swap_bonus1.c
SRCS_BONUS += push_swap_bonus2.c
SRCS_BONUS += push_swap_bonus3.c
SRCS_BONUS += push_swap_bonus4.c
SRCS_BONUS += push_swap_bonus5.c
SRCS_BONUS += push_swap_bonus6.c
SRCS_BONUS += get_next_line_bonus.c
SRCS_BONUS += get_next_line_utils_bonus.c

LIBFT = ./libft/libft.a

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(NAME_BONUS)

%.o: %.c
	$(CC) -c $(CFLAGS) $? -g3

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $@ $^ -Llibft -lft -g3
	@echo Mandatory Compile Complete! 🥳

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) -o $@ $^ -Llibft -lft -g3
	@echo Bonus Compile Complete! 🥳

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