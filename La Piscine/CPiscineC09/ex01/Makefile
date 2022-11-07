CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SRCDIR=srcs
HEADERS=includes/
SRCS=srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS=$(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

$(NAME): $(OBJS)
	ar rscv $@ $(OBJS)

clean: $(OBJS)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all