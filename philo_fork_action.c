
#include "philo.h"

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (is_all_alive(philo->info))
		print_fork(philo);
}

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (is_all_alive(philo->info))
		print_fork(philo);
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
