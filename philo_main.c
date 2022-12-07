/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:51:15 by hajeong           #+#    #+#             */
/*   Updated: 2022/11/20 10:20:10 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	fork_malloc_error(t_info info)
{
	pthread_mutex_destroy(info.print);
    pthread_mutex_destroy(info.guard);
	free(info.print);
    free(info.guard);
	return (ft_error("fork_init error"));
}

static int	philo_init_malloc_error(t_info info, pthread_mutex_t *fork)
{
    int i = info.philo_num - 1;
    
    pthread_mutex_destroy(info.print);
    pthread_mutex_destroy(info.guard);
    while (i >= 0) 
    {
        pthread_mutex_destroy(&fork[i]);
        i--;
    }
	free(fork);
	free(info.print);
    free(info.guard);
	return (ft_error("philo_init error"));
}


int	main(int argc, char *argv[])
{
	pthread_mutex_t	*fork;
	t_info			info;
	t_philo			*philo;

	if (make_info(&info, argc, argv) < 0)
		return (ft_error("make_info error"));
	if (info.philo_num <= 1)
		return (0);
	fork = fork_init(info.philo_num);
	if (fork == NULL)
		return (fork_malloc_error(info));
	philo = (t_philo *)malloc(sizeof(t_philo) * info.philo_num);
	if (philo_init(&info, &philo, fork) < 0)
		return (philo_init_malloc_error(info, fork));
	routine_start(&philo, &info);
	monitoring(&info, &philo);
	memory_free(philo, info, fork);
}
