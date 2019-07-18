/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swaps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:16:17 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/18 15:58:32 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**sa--Swap the first 2 elements at the top of stack a.
**Do nothing if there is only one or no elements.
*/

void	sa(t_lst *stack_a, t_lst *stack_b)
{
	int		temp;

	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	temp = stack_a->head->val;
	stack_a->head->val = stack_a->head->next->val;
	stack_a->head->next->val = temp;
	ft_buf("sa ", stack_a, stack_b);
}

/*
**sb--Swap the first 2 elements at the top of stack b.
**Do nothing if there is only one or no elements.
*/

void	sb(t_lst *stack_a, t_lst *stack_b)
{
	int	temp;

	if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	temp = stack_b->head->val;
	stack_b->head->val = stack_b->head->next->val;
	stack_b->head->next->val = temp;
	ft_buf("sb ", stack_a, stack_b);
}

/*
**ss--Does sa and sb at the same time.
*/

void	ss(t_lst *stack_a, t_lst *stack_b)
{
	int		temp_a;
	int		temp_b;

	if (stack_a->head == NULL || stack_a->head->next == NULL ||
		stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	temp_a = stack_a->head->val;
	stack_a->head->val = stack_a->head->next->val;
	stack_a->head->next->val = temp_a;
	temp_b = stack_b->head->val;
	stack_b->head->val = stack_b->head->next->val;
	stack_b->head->next->val = temp_b;
	ft_buf("ss ", stack_a, stack_b);
}
