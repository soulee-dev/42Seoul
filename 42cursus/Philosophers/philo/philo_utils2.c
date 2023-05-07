/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:54:01 by soulee            #+#    #+#             */
/*   Updated: 2023/05/07 16:24:18 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_all(t_philo_env *philo_env, t_philos *philos)
{
	int	i;

	if (philo_env)
	{
		i = 0;
		while (i < philo_env->num_philos)
		{
			pthread_mutex_destroy(&(philo_env->mutex_forks[i]));
			i++;
		}
		if (&(philo_env->print))
			pthread_mutex_destroy(&(philo_env->print));
		if (&(philo_env->status))
			pthread_mutex_destroy(&(philo_env->status));
		if (philo_env->mutex_forks)
			free(philo_env->mutex_forks);
	}
	if (philos)
		free(philos);
}

int	ret_error(t_philo_env *philo_env, t_philos *philos, char *s)
{
	while (*s)
		write(2, s++, 1);
	write(2, "\n", 1);
	clear_all(philo_env, philos);
	return (1);
}
