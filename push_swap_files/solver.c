/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:47:51 by tihendri          #+#    #+#             */
/*   Updated: 2019/08/12 16:22:40 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sorted(t_stack *a)
{
	t_lst	*temp;

	temp = a->head;
	while (temp)
	{
		if (temp->next && temp->next->value < temp->value)
			return (0);
		temp = temp->next;
		if (temp == a->sub_lst[a->start])
			break ;
	}
	return (1);
}

/*
**This function takes care of the numbers on stack A according to the amount
**of arguments parsed, by assigning an appropriate median to them.
**This function dictates which action to take according to the number of
**arguments parsed to stack A.
*/

static int	send_from_stack_a(t_stack *a, t_stack *b)
{
	int		count;
	long	median;

	count = get_count(a);
	median = NO_MEDIAN;
	if (count <= 7 && count > 2)
		median = low_args_median_a(a);
	else if (count > 7)
		median = real_median(a);
	if (median != NO_MEDIAN)
		work_stack_a(a, b, (int)median);
	else
		moves_on_stack_a(a, b, count);
	if (median == NO_MEDIAN)
		a->sub_lst[++(a->start)] = a->head;
	return ((median == NO_MEDIAN) ? 1 : 0);
}

static void	push_from_b(t_stack *b, t_stack *a, int count)
{
	int i;

	i = 0;
	count = (count == -1) ? 3 : count;
	while (i++ < count)
	{
		push(&b->head, &a->head, &a->tail);
		ft_putstr("pa\n");
	}
}

/*
**This function takes care of the numbers on stack A according to the amount
**of arguments parsed, by assigning an appropriate median to them.
**This function dictates which action to take according to the number of
**arguments that are on stack B.
*/

static void	send_from_stack_b(t_stack *a, t_stack *b)
{
	int		count;
	long	median;

	count = get_count(b);
	median = NO_MEDIAN;
	if (count <= 6 && count > 2)
		median = low_args_median_b(b);
	else if (count > 6)
		median = real_median(b);
	if (median != NO_MEDIAN)
		work_stack_b(a, b, (int)median);
	else
		moves_on_stack_b(a, b, count);
	if (median == NO_MEDIAN)
		push_from_b(b, a, count);
}

void		solver(t_stack *a, t_stack *b)
{
	int		ret;
	int		sort;

	if (sorted(a) && b->head == NULL)
	{
		free_stacks(a, b);
		exit(0);
	}
	while (!(sort = sorted(a)) || b->head != NULL)
	{
		if (!sort)
		{
			while ((ret = send_from_stack_a(a, b)) == 0)
				;
		}
		else
			a->sub_lst[++(a->start)] = a->head;
		send_from_stack_b(a, b);
	}
	free_stacks(a, b);
}
