/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:34:46 by soulee            #+#    #+#             */
/*   Updated: 2023/04/18 17:47:21 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "ft_printf/ft_printf.h"

typedef struct s_philo_env
{
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_must_eat;
	int				finish;
	pthread_mutex_t	*forks;
}			t_philo_env;

typedef struct s_philos
{
	int			id;
	int			left;
	int			right;
	int			time_last_eat;
	int			count_eat;
	pthread_t	thread;
	t_philo_env	*philo_env;
}			t_philos;

// initializer.c
void	init_philo_env(t_philo_env *philo_env, int argc, char *argv[]);
void	init_philos(t_philos **philos, t_philo_env *philo_env);
void	init_mutex(t_philo_env *philo_env);

// philo_utils.c
int		get_usec_now(void);
void	exit_error(char *s);
int		ft_atoi(const char *str);
#endif