
#include "philo.h"


void	print_action(t_philo *philo, long long time, int id, char *str)
{
	pthread_mutex_lock(philo->info->print);
	printf("%lld %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->info->print);
} 

void	print_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->info->print);
	printf("%lld %d is eating\n", get_relative_time(philo->info), philo->num);
	pthread_mutex_unlock(philo->info->print);
}

void	print_sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->info->print);
	printf("%lld %d is sleeping\n", get_relative_time(philo->info), philo->num);
	pthread_mutex_unlock(philo->info->print);
}

void	print_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->info->print);
	printf("%lld %d has taken a fork\n", \
		get_time() - philo->info->start_time, philo->num);
	pthread_mutex_unlock(philo->info->print);
}
