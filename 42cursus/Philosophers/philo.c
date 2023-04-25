/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:34:43 by soulee            #+#    #+#             */
/*   Updated: 2023/04/25 17:43:00 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_philo_finished2(t_philo_env *philo_env, t_philos *philos)
{
	int	i;
	int	now;

	i = 0;
	while (i < philo_env->num_philos)
	{
		pthread_mutex_lock(&(philo_env->status));
		now = get_msec_now();
		if (!now)
			exit_error("[check_philo_finished] time error");
		if (now - philos[i].time_last_eat >= philo_env->time_die)
		{
			pthread_mutex_unlock(&(philo_env->status));
			print_mutex(philo_env, philos, "died");
			pthread_mutex_lock(&(philo_env->status));
			philo_env->finished = 1;
			pthread_mutex_unlock(&(philo_env->status));
			break ;
		}
		pthread_mutex_unlock(&(philo_env->status));
		i++;
	}
}

void	check_philo_finished(t_philo_env *philo_env, t_philos *philos)
{
	while (!is_finished(philo_env))
	{
		pthread_mutex_lock(&(philo_env->status));
		if ((philo_env->time_must_eat != 0)
			&& (philo_env->num_philos == philo_env->finished_eat))
		{
			philo_env->finished = 1;
			pthread_mutex_unlock(&(philo_env->status));
			break ;
		}
		pthread_mutex_unlock(&(philo_env->status));
		check_philo_finished2(philo_env, philos);
	}
}

void	start_philo(t_philo_env *philo_env, t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philo_env->num_philos)
	{
		philos[i].time_last_eat = get_msec_now();
		if (!philos[i].time_last_eat)
			exit_error("[init_philos] time error");
		if (pthread_create(&(philos[i].thread), NULL, ft_thread, &(philos[i])))
			exit_error("[start_philo] thread create error");
		i++;
	}
	check_philo_finished(philo_env, philos);
	i = 0;
	while (i < philo_env->num_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

void	clear_all(t_philo_env *philo_env, t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philo_env->num_philos)
	{
		pthread_mutex_destroy(&(philo_env->mutex_forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(philo_env->print));
	pthread_mutex_destroy(&(philo_env->status));
	free(philo_env->mutex_forks);
	free(philos);
}

int	main(int argc, char *argv[])
{
	t_philos		*philos;
	t_philo_env		philo_env;

	if (argc < 5 || argc > 6)
		exit_error("[main] arguments error");
	memset(&philo_env, 0, sizeof(t_philo_env));
	init_philo_env(&philo_env, argc, argv);
	init_philos(&philos, &philo_env);
	init_mutex(&philo_env);
	start_philo(&philo_env, philos);
	clear_all(&philo_env, philos);
	return (0);
}
