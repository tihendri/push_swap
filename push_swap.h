/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:44:48 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/23 15:39:56 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	t_lst			**p;
	t_lst			*head;
	t_lst			*tail;
}					t_stack;

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
void				three_case(t_stack *a, char *temp);
void				sort_a(t_stack *a, int count, char *temp);

/*
**from stack_b_functions.c file, contains all the functions that
**will be applied to stack b.
*/

long				special_median_b(t_stack *b);
int					low_b(t_stack *b, char *com, int med, int count[2]);
void				split_b(t_stack *a, t_stack *b, int med, char *com);
void				three_caseb(t_stack *a, char *temp);
void				sort_b(t_stack *b, int count, char *temp);

#endif
