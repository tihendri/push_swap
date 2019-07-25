# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tihendri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 16:20:46 by tihendri          #+#    #+#              #
#    Updated: 2019/07/25 17:27:32 by tihendri         ###   ########.fr        #
#                                                                              #
#                                                                              #
# **************************************************************************** #

INCLUDES = -Ilibft/Includes -I.

LIB = libft

LIB.A = libft.a

CH_SRC_NAME = checker/main.c checker/run_input_cmnds.c

CH_SRC_NAME = checker_files/checker.c

P_SRC_NAME = push_swap_files/commands_for_moves.c \
			  push_swap_files/instructions_for_moves.c \
			  push_swap_files/midpoint.c \
			  push_swap_files/stack.c \
			  push_swap_files/stack_a_functions.c \
			  push_swap_files/stack_b_functions.c

CH_OBJ_NAME = $(CH_SRC_NAME:.c=.o)

P_OBJ_NAME =  $(P_SRC_NAME:.c=.o)

CH_SRC = $(CH_SRC_NAME)

P_SRC =  $(P_SRC_NAME)

CH_OBJ = $(CH_OBJ_NAME)

P_OBJ = $(P_OBJ_NAME)

ALL_OBJ = $(P_OBJ) $(CH_OBJ)

NAME_C = checker

NAME_P = push_swap

FLAGS = -Wall -Wextra -Werror

all : library $(NAME_C) $(NAME_P)

library :
	make -C $(LIB)

$(NAME_C) : $(CH_OBJ)
	gcc -o $@ $(CH_OBJ) $(INCLUDES) $(LIB)/$(LIB.A) -g

$(NAME_P) : $(P_OBJ)
	gcc -o $@ $(P_OBJ) $(INCLUDES) $(LIB)/$(LIB.A) -g

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(P_OBJ))
	@mkdir -p $(dir $(CH_OBJ))
	gcc -o $@ -c $< $(INCLUDES) $(FLAGS) -g

clean :
	rm -fr $(ALL_OBJ)
	make clean -C $(LIB)

fclean : clean
	rm -f $(NAME_C)
	rm -f $(NAME_P)
	make fclean -C $(LIB)

re : fclean all
