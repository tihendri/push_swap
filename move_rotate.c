/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:17:30 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/15 16:15:41 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**This function shift up all elements of stack by 1 and moves the first element
**to the end of the list.
*/

static void		rotate(t_lst **list)
{
	if ((*list)->next)
		*list = (*list)->next;
}

/*
**rotate a--shift up all elements of stack a by 1.
**The first element becomes the last one.
*/

void			ra(t_lst **stack_a, t_lst **stack_b)
{
	ft_putendl("ra");
	if (*stack_a)
		rotate(stack_a);
	(void)stack_b;
}

/*
**rotate b--shift up all elements of stack b by 1.
**The first element becomes the last one.
*/

void			rb(t_lst **stack_a, t_lst **stack_b)
{
	ft_putendl("rb");
	if (*stack_b)
		rotate(stack_b);
	(void)stack_a;
}

/*
**rr--Does ra and rb at the same time.
*/

void			rr(t_lst **stack_a, t_lst **stack_b)
{
	ft_putendl("rr");
	if (*stack_a && *stack_b)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}
