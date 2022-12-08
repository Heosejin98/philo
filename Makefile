# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seheo <seheo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 22:32:35 by seheo             #+#    #+#              #
#    Updated: 2022/12/08 22:32:36 by seheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc ##-fsanitize=thread
CFLAGS = -Wall -Wextra -Werror
SRCS = fork_init.c			\
	   free.c				\
	   make_info.c			\
	   monitoring.c			\
	   mutex_print.c		\
	   philo_action.c		\
	   philo_fork_action.c	\
	   philo_routine.c		\
	   philo_init.c			\
	   philo_main.c			\
	   philo_util.c

NAME = philo
OBJS = $(SRCS:.c=.o)
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME) -lpthread

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ 

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re
