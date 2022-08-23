#include <stdio.h>

void ft_print_alphabet(void) 
{
    int i;
    
    for(i = 0; i < 26; i++) 
    {
        printf("%c", 97 + i);
    }
}