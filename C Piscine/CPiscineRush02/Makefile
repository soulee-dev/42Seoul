CC=gcc
CFLAGS=-Wall -Wextra -Werror
TARGET=main
SRCDIR=srcs
HEADERS=includes/
SRCS=srcs/lib.c srcs/main.c
OBJS=$(SRCS:.c=.o)

all: $(TARGET) clean

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(SRCDIR)/*.o

fclean: clean
	rm -f $(TARGET)

re: fclean all
