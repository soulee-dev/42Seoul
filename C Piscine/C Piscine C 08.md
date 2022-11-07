# C Piscine C 08

## Structure
When the pointer struct comes, we can accesse to the data by using **dot operator**

Ex. `(*struct).c` 

But for shotly, we can also use **arrow operator**

Like this `struct->c`

This way is more convinient, and efficent to deal with pointer struct.

## Null pointer
```c
char *str;

str = 0;
*str = 0;
```

First `str = 0;` returns null pointer itself, but `*str = 0;`, this case pointer eventually points out `\0`.