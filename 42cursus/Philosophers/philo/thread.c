/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:35:09 by soulee            #+#    #+#             */
/*   Updated: 2023/05/01 12:09:04 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	act_philo(t_philo_env *philo_env, t_philos *philos)
{
	pthread_mutex_lock(&(philo_env->mutex_forks[philos->left]));
	print_mutex(philo_env, philos, "has taken a fork");
	if (philo_env->num_philos != 1)
	{
		pthread_mutex_lock(&(philo_env->mutex_forks[philos->right]));
		print_mutex(philo_env, philos, "has taken a fork");
		print_mutex(philo_env, philos, "is eating");
		pthread_mutex_lock(&(philo_env->status));
		philos->time_last_eat = get_msec_now();
		philos->count_eat++;
		pthread_mutex_unlock(&(philo_env->status));
		wait_time(philo_env->time_eat * 1000);
		pthread_mutex_unlock(&(philo_env->mutex_forks[philos->right]));
	}
	pthread_mutex_unlock(&(philo_env->mutex_forks[philos->left]));
	return (0);
}

int	is_finished(t_philo_env *philo_env)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&(philo_env->status));
	if (philo_env->finished)
		ret = 1;
	pthread_mutex_unlock(&(philo_env->status));
	return (ret);
}

void	*ft_thread(void *args)
{
	t_philos	*philos;
	t_philo_env	*philo_env;

	philos = args;
	philo_env = philos->philo_env;
	if (philos->id % 2)
		usleep(500);
	while (!is_finished(philo_env))
	{
		act_philo(philo_env, philos);
		if (philo_env->time_must_eat == philos->count_eat)
		{
			pthread_mutex_lock(&(philo_env->status));
			philo_env->finished_eat++;
			pthread_mutex_unlock(&(philo_env->status));
			break ;
		}
		print_mutex(philo_env, philos, "is sleeping");
		wait_time(philo_env->time_sleep * 1000);
		print_mutex(philo_env, philos, "is thinking");
	}
	return (0);
}
