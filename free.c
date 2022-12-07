
#include "philo.h"

void	memory_free(t_philo *philo, t_info info, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	while (i < info.philo_num)
	{
		pthread_join(philo[i].routine, 0);
		pthread_mutex_destroy(philo[i].guard);
		free(philo[i].guard);
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
	pthread_mutex_destroy(info.guard);
	pthread_mutex_destroy(info.print);
	free(philo);
	free(fork);
}
