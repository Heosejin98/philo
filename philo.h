#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_info
{
	long long		start_time;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_must_eat;
	int				all_alive;
	pthread_mutex_t	*guard;
	pthread_mutex_t	*print;
}					t_info;

typedef struct s_philo
{
	int				num;
	long long		eat_time;
	int				eat_count;
	int				life;
	t_info			*info;
	int				*left_fork_value;
	int				*right_fork_value;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*guard;
	pthread_t		routine;
}					t_philo;

#endif