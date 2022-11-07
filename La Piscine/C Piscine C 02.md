```c
char *str = "abcdef";
printf("%c", *str);
> a
```

\* it self represent, reference, using char \*, it returns current location in memory (In this case, it returns first char in char[])

```c
char *str = "abcdef";
printf("%s", str);
> abcdef
```

```c
char *str = "abcdef";
str++;
printf("%s", str);
> bcdef
```

```c
const *test = "abcdef";
const test2[] = "abcdef";
```
You cannot modify the value in char pointer

Char pointer is allocated in Text(in ROM). v.s.  