# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tihendri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 16:20:46 by tihendri          #+#    #+#              #
#    Updated: 2019/09/13 06:47:55 by tihendri         ###   ########.fr        #
#    Updated: 2019/08/23 06:16:41 by tihendri         ###   ########.fr        #
#                                                                              #
#                                                                              #
# **************************************************************************** #

NAME_PS	= push_swap
NAME_CH	= checker

PS_SRC	= algo_solve.c commands_for_moves.c instructions.c \
		  main.c midpoint.c stack.c stack_a_functions.c stack_b_functions.c

CH_SRC	= check_ascii.c check_digits.c \
		  check_duplicates.c check_moves.c \
		  checker_main.c error_check.c \
		  fill_stack.c free_all.c \
		  ft_array_free.c ft_array_join.c \
		  ft_array_size.c initialize_struct.c \
		  push_moves.c reverse_rotate_moves.c \
		  rotate_moves.c swap.c \
		  swap_moves.c

CFLAGS	= -Wall -Wextra -Werror

OBJ		= object_files

OBJPS	= $(addprefix $(OBJ)/,$(PS_SRC:.c=.o))
OBJCH	= $(addprefix $(OBJ)/,$(CH_SRC:.c=.o))

.PHONY: all clean fclean re

RED		=	\033[0;31m
GREEN	=	\033[0;32m
NC		=	\033[0m

HDR 		= -I./includes
LIBFT_HDR 	= -I./libft/includes
LIB_BINARY	= -L./libft -lft
LIBFT		= libft/libft.a

$(LIBFT):
	@make -C libft re

all: $(LIBFT) $(NAME_CH) $(NAME_PS) 

$(OBJ):
	@mkdir $@

$(OBJ)/%.o: %.c | $(OBJ)
	@$(CC) $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(NAME_PS): $(OBJPS) $(LIBFT)
	@echo "$(GREEN)compiling $@...$(NC)"
	@gcc $(CFLAGS) $(OBJPS) $(LIB_BINARY) -o $@
	@echo "$(GREEN)$@ compilation successful :)$(NC)"

$(NAME_CH): $(OBJCH) $(LIBFT)
	@echo "$(GREEN)compiling $@...$(NC)"
	@gcc $(CFLAGS) $(OBJCH) $(LIB_BINARY) -o $@
	@echo "$(GREEN)$@ compilation successful :)$(NC)"

test: all
	@perl ops.pl
	./run.sh

clean:
	@echo "$(RED)deleting object files...$(NC)"
	@/bin/rm -f $(OBJPS) $(OBJCH)
	@rm -rf $(OBJ)
	@make -C ./libft clean

fclean: clean
	@echo "$(RED)deleting both executables...$(NC)"
	@/bin/rm -f $(NAME_PS)
	@/bin/rm -f $(NAME_CH)
	@make -C ./libft fclean

re: fclean all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
