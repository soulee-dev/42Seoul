#!/bin/bash
gcc -Wall -Wextra -Werror -c *.c
ar rscv libft.a *.o
find . -type f -name "*.o" -delete