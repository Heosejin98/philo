
#include "philo.h"


static int	fork_value_malloc_error(t_info info)
{
	pthread_mutex_destroy(info.print);
    pthread_mutex_destroy(info.guard);
	free(info.print);
    free(info.guard);
	return (print_error("fork_init error"));
}

static int	fork_malloc_error(t_info info, int *fork_value)
{
	pthread_mutex_destroy(info.print);
    pthread_mutex_destroy(info.guard);
    free(fork_value);
	free(info.print);
    free(info.guard);
	return (print_error("fork_init error"));
}

int	main(int argc, char *argv[])
{
    t_info          philo_info;
    pthread_mutex_t	*fork;
    int             *fork_value;

    if (!(make_info(&philo_info, argc, argv)))
	    return (print_error("input date error"));
	if (fork_value_init(philo_info.philo_num) == NULL)
		return (fork_value_malloc_error(philo_info));
    if (fork_init(philo_info.philo_num) == NULL)
        return (fork_malloc_error(philo_info, fork_value));

    return (0);    
}
