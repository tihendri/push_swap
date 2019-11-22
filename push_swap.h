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

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

/*
**list structure
*/

typedef struct		s_lst
{
	struct s_lst	*next;
	struct s_lst	*prev;
	int				n;
}					t_lst;

/*
**List structure
*/

typedef struct		s_stack
{
	int				start;
	int				argc;
	int				acnt;
	t_lst			**p;
	t_lst			*head;
	t_lst			*tail;
}					t_stack;

/*
**from checker_main.c file.
*/

int					check_stack(t_stack *a);
void				display_finish(t_stack *a, t_stack *b, int ok);

/*
**from the stack.c file, file that creates the stack to be sorted.
*/

int					check_doubles(t_stack *a, int ac);
int					check_only_number(int ac, char **av);
void				build_stack(t_stack *a, t_stack *b, char **av, int ac);
void				error(void);
void				lst_addtail_fast(char *str, t_lst **back);
void				choose_stack(t_stack *a, t_stack *b, char **av, int ac);
void				build_stack_2(t_stack *a, t_stack *b, char **av, int ac);

/*
**from instructions_for_moves.c file, instructions to execute in
**commands file.
*/

void				print_stacks(t_lst *a, t_lst *b, char *line);
void				push(t_lst **from, t_lst **to, t_lst **to_tail);
void				swap(t_lst **head);
void				rotate(t_lst **head, t_lst **tail);
void				rev_rotate(t_lst **head, t_lst **tail);

/*
**from commands_for_moves.c file, call executable instructions from
**instructions file.
*/

void				swapper(char *line, t_stack *a, t_stack *b);
void				rotater(char *line, t_stack *a, t_stack *b);
void				rev_rotater(char *line, t_stack *a, t_stack *b);

/*
**from midpoint.c file, gets the median/middle of the input data,
**in order to split.
*/

int					get_count(t_stack *s);
int					get_true_median(t_stack *a);

/*
**from stack_a_functions.c file, contains all the functions that
**will be applied to stack a.
*/

long				special_median_a(t_stack *a);
int					big_a(t_stack *a, char *com, int med, int *t_rewind);
void				split_a(t_stack *a, t_stack *b, int med, char *com);
void				three_case_a(t_stack *a, char *temp);
void				sort_a(t_stack *a, int count, char *temp);

/*
**from stack_b_functions.c file, contains all the functions that
**will be applied to stack b.
*/

long				special_median_b(t_stack *b);
int					low_b(t_stack *b, char *com, int med, int count[2]);
void				split_b(t_stack *a, t_stack *b, int med, char *com);
void				three_case_b(t_stack *a, char *temp);
void				sort_b(t_stack *b, int count, char *temp);

/*
**from algo_solve.c file, contains the functions used to sort the
**arrays.
*/

int					split_stack_a(t_stack *a, t_stack *b, t_list **command);
int					sorted(t_stack *a);
void				push_b(t_stack *b, t_stack *a, int count, char *temp);
void				b_to_a(t_stack *a, t_stack *b, t_list **command);
t_list				*solver(t_stack *a, t_stack *b);

#endif
