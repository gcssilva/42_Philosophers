NAME	=	philo
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -pthread -g -fsanitize=thread
SRC		=	actions.c \
			create_philos.c \
			philo.c \
			utils.c \

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re