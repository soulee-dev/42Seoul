/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:34:46 by soulee            #+#    #+#             */
/*   Updated: 2023/05/01 12:19:59 by soulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo_env
{
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_start;
	int				time_must_eat;
	int				finished_eat;
	int				finished;
	pthread_mutex_t	print;
	pthread_mutex_t	status;
	pthread_mutex_t	*mutex_forks;
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
int		get_msec_now(void);
void	exit_error(char *s);
int		ft_atoi(const char *str);
void	print_mutex(t_philo_env *philo_env, t_philos *philos, char *s);
void	wait_time(int time, t_philo_env *philo_env);

// thread.c
int		is_finished(t_philo_env *philo_env);
int		act_philo(t_philo_env *philo_env, t_philos *philos);
void	*ft_thread(void *args);
#endif