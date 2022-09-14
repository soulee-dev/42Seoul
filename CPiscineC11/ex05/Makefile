CC=gcc
CFLAGS=-Wall -Wextra -Werror
TARGET=do-op
SRCDIR=srcs
HEADERS=includes/
SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(SRCS:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(SRCDIR)/*.o

fclean: clean
	rm -f $(TARGET)

re: fclean all
