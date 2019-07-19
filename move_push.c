/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:16:58 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/19 09:36:03 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**push a--take the first element at the top of b and put it at the top of a.
**Do nothing if b is empty.
*/

void				pa(t_lst *stack_a, t_lst *stack_b)
{
	t_node	*elem;

	if (stack_b->head != NULL)
	{
		elem = stack_b->head;
		if (stack_a->head == NULL)
		{
			stack_b->head = elem->next;
			elem->next = NULL;
			stack_a->head = elem;
			stack_a->tail = elem;
		}
		else
		{
			stack_b->head = elem->next;
			elem->next = stack_a->head;
			stack_a->head = elem;
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
	t_node	*elem;

	if (stack_a->head != NULL)
	{
		elem = stack_a->head;
		if (stack_b->head == NULL)
		{
			stack_a->head = elem->next;
			elem->next = NULL;
			stack_b->head = elem;
			stack_b->tail = elem;
		}
		else
		{
			stack_a->head = elem->next;
			elem->next = stack_b->head;
			stack_b->head = elem;
		}
		ft_buf("pb ", stack_a, stack_b);
	}
}
