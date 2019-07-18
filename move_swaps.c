/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:16:17 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/18 15:33:07 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**This function swaps the first two elements in a list.
*/

static void		list_swap(t_lst **list)
{
	t_lst	*temp;

	if ((*list)->next)
	{
		temp = *list;
		*list - (*list)->next;
		temp->next = (*list)->next;
		temp->next->prev = temp;
		(*list)->prev = temp->prev;
		temp->prev = *list;
		(*list)->next = temp;
		(*list)->prev->next = *list;
	}
}

/*
**sa--Swap the first 2 elements at the top of stack a.
**Do nothing if there is only one or no elements.
*/

void	sa(t_lst **stack_a, t_lst **stack_b)
{
	int		temp;

	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	temp = stack_a->head->val;
	stack_a->head->val = stack_a->head->next->val;
	stack_a->head->next->val = temp;
	ps_ft_buf("sa ", stack_a, stack_b);
}

/*
**sb--Swap the first 2 elements at the top of stack b.
**Do nothing if there is only one or no elements.
*/

void	sb(t_lst **stack_a, t_lst **stack_b)
{
	ft_putendl("sb");
	if (*stack_b)
		list_swap(stack_b);
	(void)stack_a;
}

/*
**ss--Does sa and sb at the same time.
*/

void	ss(t_lst **stack_a, t_lst **stack_b)
{
	ft_putendl("ss");
	if (*stack_a && *stack_b)
	{
		list_swap(stack_a);
		list_swap(stack_b);
	}
}
