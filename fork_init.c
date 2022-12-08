/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:32:52 by seheo             #+#    #+#             */
/*   Updated: 2022/12/08 22:32:52 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*fork_init(int philo_num)
{
	pthread_mutex_t	*new;
	int				i;

	i = 0;
	new = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo_num);
	if (new == NULL)
		return (NULL);
	while (i < philo_num)
	{
		pthread_mutex_init(&new[i], 0);
		i++;
	}
	return (new);
}
