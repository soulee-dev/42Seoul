CC=cc
NAME=philo
# CFLAGS=-Wall -Wextra -Werror

SRCS:=
SRCS+=philo.c
SRCS+=philo_utils.c

FT_PRINTF=./ft_printf/libftprintf.a

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $? ${CPPFLAGS} -g3

all: $(FT_PRINTF) $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF)
	${CC} -o $@ $^ -Lft_printf -lftprintf -g3
	@echo Compile Complete! 🥳

$(FT_PRINTF):
	make -C ./ft_printf

clean:
	rm -f ${OBJS}
	make clean -C ./ft_printf

fclean: clean
	make fclean -C ./ft_printf
	rm -f ${NAME}

re:
	make fclean
	make all

.PHONY: all clean fclean re