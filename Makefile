CC = cc
CFLAGS = 
SRCS =		philo.c \
			input.c 

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
