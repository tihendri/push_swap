/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:16:58 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/19 12:43:05 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**push a--take the first element at the top of b and put it at the top of a.
**Do nothing if b is empty.
*/

void				pa(t_lst *stack_a, t_lst *stack_b)
{
	t_node	*element;

	if (stack_b->head != NULL)
	{
		element = stack_b->head;
		if (stack_a->head == NULL)
		{
			stack_b->head = element->next;
			element->next = NULL;
			stack_a->head = element;
			stack_a->tail = element;
		}
		else
		{
			stack_b->head = element->next;
			element->next = stack_a->head;
			stack_a->head = element;
		}
		ft_buf("pa ", stack_a, stack_b);
	}
}

/*
**push b--take the first element at the top of a and put it at the top of b.
**Do nothing if a is empty.
*/

void				pb(t_lst *stack_a, t_lst *stack_b)
{
	t_node	*element;

	if (stack_a->head != NULL)
	{
		element = stack_a->head;
		if (stack_b->head == NULL)
		{
			stack_a->head = element->next;
			element->next = NULL;
			stack_b->head = element;
			stack_b->tail = element;
		}
		else
		{
			stack_a->head = element->next;
			element->next = stack_b->head;
			stack_b->head = element;
		}
		ft_buf("pb ", stack_a, stack_b);
	}
}
