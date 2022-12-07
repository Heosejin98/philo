/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:51:34 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/20 10:23:30 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	time_check(long long start_time, int action_time)
{
	if (get_time() - start_time >= action_time)
	{
		return (0);
	}
	else
		return (1);
}

void	eatting(t_philo *philo)
{	
	pthread_mutex_lock(philo->guard);
	philo->eat_time = get_time();
	pthread_mutex_unlock(philo->guard);
	if (is_all_alive(philo->info))
	{
		print_eating(philo);
		while (time_check(philo->eat_time, philo->info->time_to_eat))
			usleep(100);
	}
}

void	sleeping(t_philo *philo)
{
	long long	sleep_start;

	if (is_all_alive(philo->info))
	{
		sleep_start = get_time();
		print_sleeping(philo);
		while (time_check(sleep_start, philo->info->time_to_sleep))
			usleep(100);
	}
}

void	thinking(t_philo *philo)
{
	printf("%lld %d is thinking\n", get_relative_time(philo->info), philo->num);
}