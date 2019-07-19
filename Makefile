# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tihendri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 16:20:46 by tihendri          #+#    #+#              #
#    Updated: 2019/07/19 13:49:47 by tihendri         ###   ########.fr        #
#                                                                              #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re norme

SOURCE = move_push.c \
		 move_swap\
		 move_rotate\
		 move_reverse_rotate

OBJECTS = %.o
all: $(NAME)
