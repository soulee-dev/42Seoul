/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soulee <soulee@studnet.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:34:46 by soulee            #+#    #+#             */
/*   Updated: 2023/04/15 18:03:05 by soulee           ###   ########.fr       */
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
	int	num_philos;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	must_eat_time;
}			t_philo_env;

// philo_utils.c
int	ft_atoi(const char *str);
#endif