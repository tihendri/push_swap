# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tihendri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 16:20:46 by tihendri          #+#    #+#              #
#    Updated: 2019/08/12 16:34:22 by tihendri         ###   ########.fr        #
#                                                                              #
#                                                                              #
# **************************************************************************** #

NAME_PS	= push_swap
NAME_CH	= checker

PS_SRC	= algo_solve.c commands_for_moves.c instructions.c \
		  main.c midpoint.c stack.c stack_a_functions.c stack_b_functions.c

CH_SRC	= algo_solve.c commands_for_moves.c instructions.c \
		  checker_main.c midpoint.c stack.c stack_a_functions.c \
		  stack_b_functions.c

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

all: $(LIBFT) $(NAME_PS) $(NAME_CH)

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
