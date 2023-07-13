NAME	=	philo
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra
INCLUDE	=	philo.h
SRC		=	philo.c\
			utils.c\
OBJ		=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
			ar -rcs 