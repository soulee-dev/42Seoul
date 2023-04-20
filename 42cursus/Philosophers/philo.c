/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:34:43 by soulee            #+#    #+#             */
/*   Updated: 2023/04/20 18:49:54 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mutex(t_philo_env *philo_env, t_philos *philos, char *s)
{
	int	now;

	now = get_msec_now();
	if (!now)
		exit_error("[put_endl_mutex] time error");
	pthread_mutex_lock(&(philo_env->print));
	if (!is_finished(philo_env))
		printf("%d %d %s\n", now - philo_env->time_start, philos->id + 1, s);
	pthread_mutex_unlock(&(philo_env->print));
}

void	wait_time(int time, t_philo_env *philo_env)
{
	int	start;
	int	now;

	start = get_msec_now();
	if (!start)
		exit_error("[wait_time] time error");
	while (!is_finished(philo_env))
	{
		now = get_msec_now();
		if (!now)
			exit_error("[wait_time] time error");
		if (now - start >= time)
			break ;
		usleep(10);
	}
}

int	act_philo(t_philo_env *philo_env, t_philos *philos)
{
	pthread_mutex_lock(&(philo_env->mutex_forks[philos->left]));
	if (philo_env->num_philos != 1)
	{
		pthread_mutex_lock(&(philo_env->mutex_forks[philos->right]));
		print_mutex(philo_env, philos, "has taken a fork (right)");
		print_mutex(philo_env, philos, "is eating");
		pthread_mutex_lock(&(philo_env->status));
		philos->time_last_eat = get_msec_now();
		philos->count_eat++;
		pthread_mutex_unlock(&(philo_env->status));
		wait_time(philo_env->time_eat, philo_env);
		pthread_mutex_unlock(&(philo_env->mutex_forks[philos->right]));
	}
	pthread_mutex_unlock(&(philo_env->mutex_forks[philos->left]));
	return (0);
}
//(1) 5번이 포포크  안안집집게게하하기기(양양쪽  포포크크를  모모두  집집을을수수있있을을떄떄만  집집게  하하기기
//(2) 뮤텍스 하나더 만들어보기?
// 그후 데이터 레이스 잡기
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
		usleep(1000);
	while (!is_finished(philo_env))
	{
		act_philo(philo_env, philos);
		if (philo_env->time_must_eat == philos->count_eat)
		{
			philo_env->finished_eat++;
			break ;
		}
		print_mutex(philo_env, philos, "is sleeping");
		wait_time(philo_env->time_sleep, philo_env);
		print_mutex(philo_env, philos, "is thinking");
	}
	return (0);
}

void	check_philo_finished(t_philo_env *philo_env, t_philos *philos)
{
	int	i;
	int	now;

	while (!is_finished(philo_env))
	{
		if ((philo_env->time_must_eat != 0)
			&& (philo_env->num_philos == philo_env->finished_eat))
		{
			pthread_mutex_lock(&(philo_env->status));
			philo_env->finished = 1;
			pthread_mutex_unlock(&(philo_env->status));
			break ;
		}
		i = 0;
		while (i < philo_env->num_philos)
		{
			now = get_msec_now();
			if (!now)
				exit_error("[check_philo_finished] time error");
			if (now - philos[i].time_last_eat >= philo_env->time_die)
			{
				print_mutex(philo_env, philos, "died");
				pthread_mutex_lock(&(philo_env->status));
				philo_env->finished = 1;
				pthread_mutex_unlock(&(philo_env->status));
				break ;
			}
		}
	}
}

void	start_philo(t_philo_env *philo_env, t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philo_env->num_philos)
	{
		philos[i].time_last_eat = get_msec_now();
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
	return (0);
}

// https://techdebt.tistory.com/32