/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:18:38 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/19 12:48:59 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**reverse rotate a--shift down all elements of stack a by 1.
**The last element becomes the first one.
*/

void				rra(t_lst *stack_a, t_lst *stack_b)
{
	t_node	*element;

	if (stack_a->head != NULL && stack_a->head != stack_a->tail)
	{
		element = stack_a->head;
		while (element->next != stack_a->tail)
			element = element->next;
		element->next->next = stack_a->head;
		stack_a->head = element->next;
		element->next = NULL;
		stack_a->tail = element;
		ft_buf("rra ", stack_a, stack_b);
	}
}

/*
**reverse rotate b--shift down all elements of stack b by 1.
**The last element becomes the first one.
*/

void				rrb(t_lst *stack_a, t_lst *stack_b)
{
	t_node	*element;

	if (stack_b->head != NULL && stack_b->head != stack_b->tail)
	{
		element = stack_b->head;
		while (element->next != stack_b->tail)
			element = element->next;
		element->next->next = stack_b->head;
		stack_b->head = element->next;
		element->next = NULL;
		stack_b->tail = element;
		ft_buf("rrb ", stack_a, stack_b);
	}
}

/*
**rrr does rra and rrb at the same time.
*/

void				rrr(t_lst *stack_a, t_lst *stack_b)
{
	t_node	*element;

	if ((stack_a->head != NULL && stack_a->head != stack_a->tail) ||
	(stack_b->head != NULL && stack_b->head != stack_b->tail))
	{
		element = stack_a->head;
		while (element->next != stack_a->tail)
			element = element->next;
		element->next->next = stack_a->head;
		stack_a->head = element->next;
		element->next = NULL;
		stack_a->tail = element;
		element = stack_b->head;
		while (element->next != stack_b->tail)
			element = element->next;
		element->next->next = stack_b->head;
		stack_b->head = element->next;
		element->next = NULL;
		stack_b->tail = element;
		ft_buf("rrr ", stack_a, stack_b);
	}
}
