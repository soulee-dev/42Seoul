CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all: $(NAME)

.PHONY: clean fclean all re

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	ar rscu $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all