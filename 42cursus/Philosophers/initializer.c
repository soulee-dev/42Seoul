/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:46:21 by soulee            #+#    #+#             */
/*   Updated: 2023/04/20 13:05:47 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo_env(t_philo_env *philo_env, int argc, char *argv[])
{
	philo_env->num_philos = ft_atoi(argv[1]);
	philo_env->time_start = get_usec_now();
	philo_env->time_die = ft_atoi(argv[2]);
	philo_env->time_eat = ft_atoi(argv[3]);
	philo_env->time_sleep = ft_atoi(argv[4]);
	if (!philo_env->time_start)
		exit_error("[init_philo_env] time error");
	if (philo_env->num_philos <= 0 || philo_env->time_die <= 0
		|| philo_env->time_eat <= 0 || philo_env->time_sleep <= 0)
		exit_error("[init_philo_env] arguments error");
	if (argc == 6)
	{
		philo_env->time_must_eat = ft_atoi(argv[5]);
		if (philo_env->time_must_eat <= 0)
			exit_error("[init_philo_env] arguments error");
	}
}

void	init_philos(t_philos **philos, t_philo_env *philo_env)
{
	int	i;

	i = 0;
	*philos = malloc(sizeof(t_philos) * philo_env->num_philos);
	if (!philos)
		exit_error("[init_philos] malloc error");
	while (i < philo_env->num_philos)
	{
		(*philos)[i].philo_env = philo_env;
		(*philos)[i].id = i;
		(*philos)[i].left = i;
		(*philos)[i].right = (i + 1) % philo_env->num_philos;
		(*philos)[i].time_last_eat = get_usec_now();
		(*philos)[i].count_eat = 0;
		if (!((*philos)[i].time_last_eat))
			exit_error("[init_philos] time error");
		i++;
	}
}

void	init_mutex(t_philo_env *philo_env)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(philo_env->print), NULL))
		exit_error("[init_mutex] mutex init error");
	philo_env->forks = malloc(sizeof(pthread_mutex_t) * philo_env->num_philos);
	if (!philo_env->forks)
		exit_error("[init_mutex] malloc error");
	while (i < philo_env->num_philos)
	{
		if (pthread_mutex_init(&(philo_env->forks[i]), NULL))
			exit_error("[init_mutex] mutex init error");
		i++;
	}
}
