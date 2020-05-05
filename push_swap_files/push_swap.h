/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:44:48 by tihendri          #+#    #+#             */
/*   Updated: 2019/08/12 16:25:58 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NO_MEDIAN 2147483648

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

/*
**Data structure
*/

typedef struct		s_lst
{
	struct s_lst	*next;
	struct s_lst	*prev;
	int				value;
}					t_lst;

/*
**Data structure
**sub_lst is mainly used for the functions involved with the median,
**so I use that instead of creating a whole new struct for it.
**It is the 2-dimensional component of this linked-list.
*/

typedef struct		s_stack
{
	int				start;
	int				argc;
	int				argc_temp;
	t_lst			**sub_lst;
	t_lst			*head;
	t_lst			*tail;
}					t_stack;

/*
**from the choose_stack.c file
*/

void				choose_stack(t_stack *a, t_stack *b, char **av, int ac);

/*
**from the stack.c file, file that creates the stack to be sorted.
*/

void				build_stack(t_stack *a, t_stack *b, char **av, int ac);
void				build_stack_str(t_stack *a, t_stack *b, char **av, int ac);

/*
**from instructions.c file, instructions to execute.
*/

void				push(t_lst **from, t_lst **to, t_lst **to_tail);
void				swap(t_lst **head);
void				rotate(t_lst **head, t_lst **tail);
void				rev_rotate(t_lst **head, t_lst **tail);

/*
**from median file, gets the median/middle of the input data,
**in order to split.
*/

int					get_count(t_stack *stack);
int					real_median(t_stack *stack);
long				low_args_median_b(t_stack *b);
long				low_args_median_a(t_stack *a);

/*
**from stack_a_functions.c file, contains all the functions that
**will be applied to stack a.
*/

void				work_stack_a(t_stack *a, t_stack *b, int median, char *command);
void				moves_on_stack_a(t_stack *a, t_stack *b, int count, char *command);

/*
**from stack_b_functions.c file, contains all the functions that
**will be applied to stack b.
*/

void				work_stack_b(t_stack *a, t_stack *b, int median, char *commmand);
void				moves_on_stack_b(t_stack *a, t_stack *b, int count, char *command);

/*
**from algo_solve.c file, contains the functions used to sort the
**arrays.
*/

t_list				*solver(t_stack *a, t_stack *b);

#endif
