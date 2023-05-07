CC=cc
NAME=philo
CFLAGS=-Wall -Wextra -Werror

SRCS:=
SRCS+=philo.c
SRCS+=initializer.c
SRCS+=philo_utils.c
SRCS+=thread.c
SRCS+=philo_utils2.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $? -g3

all: $(NAME)

$(NAME): $(OBJS)
	${CC} -o $@ $^ -g3
	@echo Compile Complete! 🥳

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:
	make fclean
	make all

.PHONY: all clean fclean re