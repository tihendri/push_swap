/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_for_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:14:13 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/26 11:56:57 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
**Checker checks the input from user and runs the input commands until it
**encounters an error or it's done.
**This function acts as the implementation of the swapping function.
**Swap first two elements of respective stacks.
*/

void	swapper(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "sa"))
	{
		swap(&a->head);
		return ;
	}
	if (!ft_strcmp(line, "sb"))
	{
		swap(&b->head);
		return ;
	}
	swap(&a->head);
	swap(&b->head);
}

/*
**This function acts as the implementation of the rotating function.
**Shifts up all elements of respective stacks by one and the first element
**becomes the last.
*/

void	rotater(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "ra"))
	{
		rotate(&a->head, &a->tail);
		return ;
	}
	if (!ft_strcmp(line, "rb"))
	{
		rotate(&b->head, &b->tail);
		return ;
	}
	rotate(&a->head, &a->tail);
	rotate(&b->head, &b->tail);
}

/*
**This function acts as the implementation of the reverse rotating function.
**Shifts up all elements of respective stacks by one and the last element
**becomes the first.
*/

void	rev_rotater(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "rra"))
	{
		rev_rotate(&a->head, &a->tail);
		return ;
	}
	if (!ft_strcmp(line, "rrb"))
	{
		rev_rotate(&b->head, &b->tail);
		return ;
	}
	rev_rotate(&a->head, &a->tail);
	rev_rotate(&b->head, &b->tail);
}
