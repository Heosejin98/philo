
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
