# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tihendri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 16:20:46 by tihendri          #+#    #+#              #
#    Updated: 2019/12/19 23:25:34 by tihendri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS	= push_swap
NAME_CH	= checker

PS_SRC	= push_swap_files/solver.c \
		  push_swap_files/instructions.c \
		  push_swap_files/main.c \
		  push_swap_files/median.c \
		  push_swap_files/stack.c \
		  push_swap_files/stack_a_functions.c \
		  push_swap_files/stack_b_functions.c \
		  push_swap_files/choose_stack.c \
		  push_swap_files/free_functions.c \
		  push_swap_files/ft_lstaddtail.c \
		  push_swap_files/ft_lstnew_str.c

CH_SRC	= checker_files/check_sorted.c \
		  checker_files/exec_moves.c \
		  checker_files/checker_main.c \
		  checker_files/ft_put.c \
		  checker_files/error_check.c \
		  checker_files/populate_stack.c \
		  checker_files/ft_array_func.c \
		  checker_files/initialize_struct.c \
		  checker_files/all_moves.c \
		  checker_files/visualize.c \
		  checker_files/free_all.c

CFLAGS	= -Wall -Wextra -Werror

OBJPS	= $(PS_SRC:.c=.o)
OBJCH	= $(CH_SRC:.c=.o)

.PHONY: all clean fclean re

RED		=	\033[0;31m
GREEN	=	\033[0;32m
NC		=	\033[0m

HDR 		= -I./includes
LIBFT_HDR 	= -I./libft/includes
LIB_BINARY	= -L./libft -lft
LIBFT		= libft/libft.a

all: $(LIBFT) $(NAME_CH) $(NAME_PS)

$(OBJ):
	@mkdir $@

$(OBJ)/%.o: %.c | $(OBJ)
	@$(CC) $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(LIBFT):
	@make -C libft re

$(NAME_PS): $(OBJPS) $(LIBFT)
	@echo "$(GREEN)compiling $@...$(NC)"
	@gcc -g $(CFLAGS) $(OBJPS) $(LIB_BINARY) -o $@
	@echo "$(GREEN)$@ compilation successful :)$(NC)"

$(NAME_CH): $(OBJCH) $(LIBFT)
	@echo "$(GREEN)compiling $@...$(NC)"
	@gcc $(CFLAGS) $(OBJCH) $(LIB_BINARY) -o $@
	@echo "$(GREEN)$@ compilation successful :)$(NC)"

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
