/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:03:48 by soulee            #+#    #+#             */
/*   Updated: 2022/08/31 16:10:41 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime_check(int n, int d)
{
	int	result;

	result = 0;
	if (d <= 0)
		return (0);
	if (n % d == 0)
		result = 1;
	result += ft_is_prime_check(n, d - 1);
	return (result);
}

int	ft_find_next_prime(int nb)
{
	nb += 1;
	while (ft_is_prime_check(nb, nb) != 2)
		nb++;
	return (nb);
}
