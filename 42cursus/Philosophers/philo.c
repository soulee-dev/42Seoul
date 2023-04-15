/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:34:43 by soulee            #+#    #+#             */
/*   Updated: 2023/04/15 18:07:03 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	struct timeval	start_time;
	struct timeval	end_time;
	t_philo_env		philo_env;

	if (argc < 5 || argc > 6)
	{
		write(2, "arguments error\n", 16);
		exit(1);
	}
	// philo_env.num_philos = ft_atoi(argv[1]);
	// philo_env.die_time = ft_atoi(argv[2]);
	// philo_env.eat_time = ft_atoi(argv[3]);
	// philo_env.sleep_time = ft_atoi(argv[4]);
	// if (argc == 5)
	// 	philo_env.must_eat_time = ft_atoi(argv[5]);
	gettimeofday(&start_time, NULL);
	while (1)
	{
		gettimeofday(&end_time, NULL);
		printf("%ld\n", (end_time.tv_sec - start_time.tv_sec));
		// usleep(1000000);
	}
	return (0);
}
