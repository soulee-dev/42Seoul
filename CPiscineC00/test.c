#include <stdio.h>
#include "ex00/ft_putchar.c"
#include "ex01/ft_print_alphabet.c"
#include "ex02/ft_print_reverse_alphabet.c"
#include "ex03/ft_print_numbers.c"
#include "ex04/ft_is_negative.c"
#include "ex05/ft_print_comb.c"
// #include "ex06/ft_print_comb2.c"
#include "ex07/ft_putnbr.c"
// #include "ex01/ft_print_combn.c"
int	main(void)
{
	printf("\n=====[ex00]=====\n");
	printf("[S 가 출력되면 성공]\n");
	char	zero;
	zero = 'S';
	ft_putchar(zero);
	printf("\n\n=====[ex01]=====\n");
	printf("[모든 알파벳이 순서대로 나오면 성공]\n");
	ft_print_alphabet();
	printf("\n\n=====[ex02]=====\n");
	printf("[모든 알파벳이 순서 꺼꾸로 나오면 성공]\n");
	ft_print_reverse_alphabet();
	printf("\n\n=====[ex03]=====\n");
	printf("[모든 숫자가 오름차순으로 나오면 성공]\n");
	ft_print_numbers();
	printf("\n\n=====[ex04]=====\n");
	printf("[P, P, N이 나오면 성공]\n");
	ft_is_negative(0);
	ft_is_negative(5);
	ft_is_negative(-8);
	printf("\n\n=====[ex05]=====\n");
	printf("[012부터 789까지 작은 자리수 숫자가 항상 크면 성공]\n");
	ft_print_comb();
	// printf("\n\n=====[ex06]=====\n");
	// printf("[00 01부터 98 99까지 뒤의 숫자가 앞의 숫자보다 크면 성공]\n");
	// ft_print_comb2();
	printf("\n\n=====[ex07]=====\n");
	printf("[212, -616, 2147483647, -2147483648이 나오면 성공(최대, 최소값)]\n");
	ft_putnbr(212);
	ft_putnbr(-616);
	ft_putnbr(2147483647);
	ft_putnbr(-2147483638);
	// printf("\n\n=====[ex08]=====\n");
	// printf("[2개, 5개, 9개씩 나오면 성공\n]");
	// ft_print_combn(2);
	// printf("\n==========\n");
	// ft_print_combn(6);
	// printf("\n==========\n");
	// ft_print_combn(9);
}