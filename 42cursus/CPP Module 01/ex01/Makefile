CC=c++
NAME=zomebie
CPPFLAGS=-Wall -Wextra -Werror -std=c++98
                                                                                                                  
SRCS:=
SRCS+=main.cpp
SRCS+=Zombie.cpp
SRCS+=zombieHorde.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) -c $(CPPFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:
	make fclean
	make all

.PHONY: all clean fclean re