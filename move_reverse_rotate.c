/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:18:38 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/15 16:15:06 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			reverse_rotate(t_lst **list)
{
	if ((*list)->prev)
		*list = (*list)->prev;
}

/*
**reverse rotate a--shift down all elements of stack a by 1.
**The last element becomes the first one.
*/

void				rra(t_lst **stack_a, t_lst **stack_b)
{
	ft_putendl("rra");
	if (*stack_a)
		reverse_rotate(stack_a);
	(void)stack_b;
}

void				rrb(t_lst **stack_a, t_lst **stack_b)
{
	ft_putendl("rrb");
	if (*stack_b)
		reverse_rotate(stack_b);
	(void)stack_a;
}

void				rrr(t_lst **stack_a, t_lst **stack_b)
{
	ft_putendl("rrr");
	if (*stack_a && *stack_b)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}
