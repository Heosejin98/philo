/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:27:54 by seheo             #+#    #+#             */
/*   Updated: 2022/12/08 22:50:55 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *str)
{
	printf("%s\n", str);
	return (-1);
}

long long	get_time(void)
{
	struct timeval	time;
	long long		now_time;

	gettimeofday(&time, 0);
	now_time = time.tv_usec / 1000 + time.tv_sec * 1000;
	return (now_time);
}

long long	get_relative_time(t_info *info)
{
	return (get_time() - info->start_time);
}
