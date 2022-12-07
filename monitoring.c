
#include "philo.h"

static void	check_someone_die(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(philo->guard);
	if (philo->life)
	{
		if (get_time() - philo->eat_time >= philo->info->time_to_die)
		{
			pthread_mutex_lock(info->guard);
			info->all_alive = 0;
			print_action(philo, get_relative_time(info), philo->num, "died");
			pthread_mutex_unlock(info->guard);
		}
	}
	pthread_mutex_unlock(philo->guard);
}

static void end_meal(int philo_num, t_philo **philo)
{
	t_philo *philo_arr;

	philo_arr = *philo;
	while (philo_num >= 0) {
		pthread_detach(philo_arr[philo_num].routine);
		philo_num--;
	}
}

void	monitoring(t_info *info, t_philo **philo)
{
	int		i;
	int		cnt;
	t_philo	*temp;

	temp = *philo;
	while (is_all_alive(info))
	{
		i = 0;
		cnt = 0;
		while (i < info->philo_num && is_all_alive(info))
		{
			check_someone_die(&temp[i], info);
			pthread_mutex_lock(temp[i].guard);
			if (temp[i].life == 0)
				cnt++;
			pthread_mutex_unlock(temp[i].guard);
			i++;
		}
		if (cnt == info->philo_num)
		{
			pthread_mutex_lock(info->guard);
			end_meal(info->philo_num - 1, philo);
			info->all_alive = 0;
			pthread_mutex_unlock(info->guard);
		}
	}
}
