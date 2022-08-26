#include <stdio.h>

#include "ex08/ft_strlowcase.c"
#include "ex09/ft_strcapitalize.c"
#include "ex10/ft_strlcpy.c"
#include "ex11/ft_putstr_non_printable.c"

int	main(void)
{
	// ex08
	printf("ex08\n");
	char test_strlowcase[] = "ABCDEFG";
	printf("abcdefg");
	printf("%s", ft_strlowcase(test_strlowcase));


	printf("\n\n");
	// ex09
	printf("ex09\n");
	char test_strcapitalize[] = "sAlut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un\n");
	printf("%s", ft_strcapitalize(test_strcapitalize));

	printf("\n\n");
	// ex10
	char test_strlcpy_src[] = "123456";
	char test_strlcpy_dest[20];
	printf("dest = 1\nreturn = 2");
	size_t ret = ft_strlcpy(test_strlcpy_dest, test_strlcpy_src, 2);
	printf("dest = %s\nreturn = %zu", test_strlcpy_dest, ret);

	printf("\n\n");
	// ex11
	char test_putstr_non_printable[] = "wow\n";
	ft_putstr_non_printable(test_putstr_non_printable);

}