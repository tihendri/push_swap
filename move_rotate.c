/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:17:30 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/19 12:50:06 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**rotate a--shift up all elements of stack a by 1.
**The first element becomes the last one.
*/

void			ra(t_lst *stack_a, t_lst *stack_b)
{
	t_node	*element;

	if ((stack_a->head != NULL || stack_a->head->next != NULL) &&
	stack_a->head != stack_a->tail)
	{
		element = stack_a->head;
		stack_a->head = stack_a->head->next;
		element->next = NULL;
		stack_a->tail->next = element;
		stack_a->tail = element;
		ft_buf("ra ", stack_a, stack_b);
	}
}

/*
**rotate b--shift up all elements of stack b by 1.
**The first element becomes the last one.
*/

void			rb(t_lst *stack_a, t_lst *stack_b)
{
	t_node	*element;

	if ((stack_b->head != NULL || stack_b->head->next != NULL) &&
	stack_b->head != stack_b->tail)
	{
		element = stack_b->head;
		stack_b->head = stack_b->head->next;
		element->next = NULL;
		stack_b->tail->next = element;
		stack_b->tail = element;
		ft_buf("rb ", stack_a, stack_b);
	}
}

/*
**rr--Does ra and rb at the same time.
*/

void			rr(t_lst *stack_a, t_lst *stack_b)
{
	t_node	*element;

	if (((stack_b->head != NULL || stack_b->head->next != NULL) &&
		stack_b->head != stack_b->tail) || ((stack_a->head != NULL ||
		stack_a->head->next != NULL) && stack_a->head != stack_a->tail))
	{
		element = stack_a->head;
		stack_a->head = stack_a->head->next;
		element->next = NULL;
		stack_a->tail->next = element;
		stack_a->tail = element;
		element = stack_b->head;
		stack_b->head = stack_b->head->next;
		element->next = NULL;
		stack_b->tail->next = element;
		stack_b->tail = element;
		ft_buf("rr ", stack_a, stack_b);
	}
}
