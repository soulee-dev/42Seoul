#include <stdio.h>

void ft_print_reverse_alphabet(void) {

    for(int i = 0; i < 25; i++) {
        printf("%c", 122 - i);
    }
}