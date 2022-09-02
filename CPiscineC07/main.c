#include <stdio.h>
#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
// #include "ex02/ft_ultimate_range.c"
#include "ex03/ft_strjoin.c"


#include <stdlib.h>

int	main(void)
{
	char	*str = "abc";
	char	*new_ptr;

	new_ptr = ft_strdup(str);
	printf("%p, %s\n", &str, str);
	printf("%p, %s", new_ptr, new_ptr);

	printf("\n\n");
	int	i;
	i = 0;
	int	*arr;
	arr = ft_range(1, 3);
	while (i < sizeof(arr))
		printf("%d ", arr[i++]);

	// printf("\n\n");
	// int **range;
	// printf("%d", ft_ultimate_range(range, 1, 3));
	
	// char	**strs[2];
	// strs[0] = "aaaa";
	// strs[1] = "bbbb";
	// printf("\n\n");
	// printf("%s", ft_strjoin(2, strs, ","));
	// return (0);
}