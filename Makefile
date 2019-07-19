# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tihendri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 16:20:46 by tihendri          #+#    #+#              #
#    Updated: 2019/07/19 11:39:07 by tihendri         ###   ########.fr        #
#                                                                              #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re norme

all: $(NAME)
