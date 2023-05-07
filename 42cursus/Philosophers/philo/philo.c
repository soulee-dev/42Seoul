/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:34:43 by soulee            #+#    #+#             */
/*   Updated: 2023/05/07 16:26:40 by soulee           ###   ########.fr       */
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

int	start_philo(t_philo_env *philo_env, t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philo_env->num_philos)
	{
		philos[i].time_last_eat = get_msec_now();
		if (pthread_create(&(philos[i].thread), NULL, ft_thread, &(philos[i])))
			return (ret_error(philo_env, philos, \
				"[start_philo] thread create error"));
		i++;
	}
	check_philo_finished(philo_env, philos);
	i = 0;
	while (i < philo_env->num_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_philos		*philos;
	t_philo_env		philo_env;

	if (argc < 5 || argc > 6)
		return (ret_error(0, 0, "[main] arguments error"));
	memset(&philo_env, 0, sizeof(t_philo_env));
	if (init_philo_env(&philo_env, argc, argv))
		return (0);
	if (init_philos(&philos, &philo_env))
		return (0);
	if (init_mutex(&philo_env))
		return (ret_error(0, philos, 0));
	if (start_philo(&philo_env, philos))
		return (0);
	clear_all(&philo_env, philos);
	return (0);
}
