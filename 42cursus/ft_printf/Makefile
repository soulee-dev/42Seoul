CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
SRCS :=
BONUS_SRCS :=

OBJS=$(SRCS:.c=.o)
BONUS_OBJS=$(BONUS_SRCS:.c=.o)
ALL_SRCS = $(SRCS) $(BONUS_SRCS)
ALL_OBJS = $(OBJS) $(BONUS_OBJS)

define object_goals
$(call $(if $(filter bonus, $(MAKECMDGOALS)), ALL_OBJS, OBJS))
endef

all: $(NAME)

.PHONY: bonus clean fclean all re

%.o: %.c
	@$(CC) $(CFLAGS) -c $?

$(NAME): $(object_goals)
	@ar rscu $(NAME) $(object_goals)

bonus: $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
