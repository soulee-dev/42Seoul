/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:34:43 by soulee            #+#    #+#             */
/*   Updated: 2023/04/20 14:21:18 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mutex(t_philo_env *philo_env, t_philos *philos, char *s)
{
	int	now;

	now = get_usec_now();
	if (!now)
		exit_error("[put_endl_mutex] time error");
	pthread_mutex_lock(&(philo_env->print));
	printf("%d %d %s", now - philo_env->time_start, philos->id + 1, s);
	pthread_mutex_unlock(&(philo_env->print));
}

int	act_philo(t_philo_env *philo_env, t_philos *philos)
{
	pthread_mutex_lock(&(philo_env->forks[philos->left]));
	print_mutex(philo_env, philos, "has taken a fork");
	if (philo_env->num_philos != 1)
	{
		pthread_mutex_lock(&(philo_env->forks[philos->right]));
		pthread_mutex_unlock(&(philo_env->forks[philos->right]));
	}
}

void	*ft_thread(void *args)
{
	t_philos	*philos;
	t_philo_env	*philo_env;

	philos = args;
	philo_env = philos->philo_env;
	if (philos->id & 2)
		usleep(1000);
	act_philo(philo_env, philos);
	// while (!philo_env->finish)
	// {
		
	// }

	return (0);
}

void	start_philo(t_philo_env *philo_env, t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philo_env->num_philos)
	{
		philos[i].time_last_eat = get_usec_now();
		if (pthread_create(&(philos[i].thread), NULL, ft_thread, &(philos[i])))
			exit_error("[start_philo] thread create error");
		i++;
	}
	i = 0;
	while (i < philo_env->num_philos)
	{
		pthread_join(philos[i].thread, NULL);
	}
}

int	main(int argc, char *argv[])
{
	t_philos		*philos;
	t_philo_env		philo_env;

	if (argc < 5 || argc > 6)
		exit_error("[main] arguments error");
	memset(&philo_env, 0, sizeof(t-philo_env));
	init_philo_env(&philo_env, argc, argv);
	init_philos(&philos, &philo_env);
	init_mutex(&philo_env);
	start_philo(&philo_env, philos);
	return (0);
}

// https://techdebt.tistory.com/32