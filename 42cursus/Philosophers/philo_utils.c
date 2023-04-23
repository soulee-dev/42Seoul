/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:49:30 by soulee            #+#    #+#             */
/*   Updated: 2023/04/23 15:41:24 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (((int)(*str) >= 9 && (int)(*str) <= 13) || (int)(*str) == 32)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			num = num * 10 + (*str - '0');
			str++;
		}
		else
			return (sign * num);
	}
	return (sign * num);
}

void	exit_error(char *s)
{
	while (*s)
		write(2, s++, 1);
	write(2, "\n", 1);
	exit(1);
}

int	get_msec_now(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_mutex(t_philo_env *philo_env, t_philos *philos, char *s)
{
	int	now;

	pthread_mutex_lock(&(philo_env->print));
	now = get_msec_now();
	if (!now)
		exit_error("[put_endl_mutex] time error");
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
		usleep(100);
	}
}
