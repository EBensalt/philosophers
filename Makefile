# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 19:51:34 by ebensalt          #+#    #+#              #
#    Updated: 2022/08/14 04:35:28 by ebensalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
C		= philo.c \
		  my_atoi.c \
		  philo_utils.c \
		  philo2.c \
		  philo3.c
O		= $(C:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
all		: $(NAME)
$(NAME)	: $(O)
	$(CC) $(CFLAGS) $(O) -o $(NAME)
clean	:
	rm -rf *.o
fclean	: clean
	rm -rf $(NAME)
re		: fclean all