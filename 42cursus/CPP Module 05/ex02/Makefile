CC=c++
NAME=forms
CXXFLAGS=-Wall -Wextra -Werror -std=c++98

RM=rm -f

SRCS:=
SRCS+=main.cpp
SRCS+=Bureaucrat.cpp
SRCS+=AForm.cpp
SRCS+=ShrubberyCreationForm.cpp
SRCS+=RobotomyRequestForm.cpp
SRCS+=PresidentialPardonForm.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) -c $(CXXFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) ${OBJS}

fclean: clean
	$(RM) ${NAME}

re:
	make fclean
	make all

.PHONY: all clean fclean re