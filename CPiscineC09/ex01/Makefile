CC=gcc
CFLAGS= -Wall -Wextra -Werror
TARGET=name
HEADER=includes
SRCSDIR=srcs
SRCS=$(wildcard $(SRCSDIR)/*.c)
OBJS=$(SRCS:.c=.o)

all: $(TARGET)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -r $(SRCSDIR)/*.o

fclean: clean
	rm -r $(TARGET)

re: fclean all