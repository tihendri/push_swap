/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:18:38 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/19 09:47:14 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**reverse rotate a--shift down all elements of stack a by 1.
**The last element becomes the first one.
*/

void				rra(t_lst *stack_a, t_lst *stack_b)
{
	t_node	*elem;

	if (stack_a->head != NULL && stack_a->head != stack_a->tail)
	{
		elem = stack_a->head;
		while (elem->next != stack_a->tail)
			elem = elem->next;
		elem->next->next = stack_a->head;
		stack_a->head = elem->next;
		elem->next = NULL;
		stack_a->tail = elem;
		ft_buf("rra ", stack_a, stack_b);
	}
}

/*
**reverse rotate b--shift down all elements of stack b by 1.
**The last element becomes the first one.
*/

void				rrb(t_lst *stack_a, t_lst *stack_b)
{
	t_node	*elem;

	if (stack_b->head != NULL && stack_b->head != stack_b->tail)
	{
		elem = stack_b->head;
		while (elem->next != stack_b->tail)
			elem = elem->next;
		elem->next->next = stack_b->head;
		stack_b->head = elem->next;
		elem->next = NULL;
		stack_b->tail = elem;
		ft_buf("rrb ", stack_a, stack_b);
	}
}

/*
**rrr does rra and rrb at the same time.
*/

void				rrr(t_lst *stack_a, t_lst *stack_b)
{
	t_node	*elem;

	if ((stack_a->head != NULL && stack_a->head != stack_a->tail) ||
	(stack_b->head != NULL && stack_b->head != stack_b->tail))
	{
		elem = stack_a->head;
		while (elem->next != stack_a->tail)
			elem = elem->next;
		elem->next->next = stack_a->head;
		stack_a->head = elem->next;
		elem->next = NULL;
		stack_a->tail = elem;
		elem = stack_b->head;
		while (elem->next != stack_b->tail)
			elem = elem->next;
		elem->next->next = stack_b->head;
		stack_b->head = elem->next;
		elem->next = NULL;
		stack_b->tail = elem;
		ft_buf("rrr ", stack_a, stack_b);
	}
}
