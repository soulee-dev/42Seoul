CC=c++
NAME=span
CXXFLAGS=-Wall -Wextra -Werror -std=c++98 -g3

RM=rm -f

SRCS:=
SRCS+=main.cpp
SRCS+=Span.cpp


OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) -c $(CXXFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) ${OBJS}

fclean: clean
	$(RM) ${NAME}

re:
	make fclean
	make all

.PHONY: all clean fclean re