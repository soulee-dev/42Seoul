#include <stdio.h>

int	main()
{
	char c = 'a';

	long long d = c & (1 << 1);
	printf("%lld", d);
}