/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:17:30 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 23:18:10 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**This function will check the values on the stack:
**if the number is smaller than the median, rotate it to the back
**of the stack.
**This is so that numbers that should be at the front of the stack,
**i.e. smaller numbers, can be pushed to the front in numerical order
**from smallest to largest.
**This function works opporsite to the "num_larger_than_median"
**function in stack_a_functions.c file
*/

static int	smaller_than_median(t_stack *b, int med, int count[2])
{
	int		skips;
	t_lst	*temp;

	skips = 0;
	temp = b->head;
	while (temp != b->sub_lst[b->start] && temp->value <= med)
	{
		skips++;
		temp = temp->next;
	}
	if (temp == b->sub_lst[b->start])
		return (0);
	count[0] += skips;
	while (skips--)
	{
		rotate(&b->head, &b->tail);
		// ft_strcat(com, "rb\n");
		ft_putstr("rb\n");
	}
	return (1);
}

/*
**This function will be the "driving force" of the operations
**for stack B, by continuously pushing to stack A if the number
**is higher than the median
*/

void		work_stack_b(t_stack *a, t_stack *b, int median)
{
	int		count[2];

	count[0] = 0;
	count[1] = 0;
	while (b->head != b->sub_lst[b->start])
	{
		if (b->head->value > median)
		{
			push(&b->head, &a->head, &a->tail);
			// ft_strcat(command, "pa\n");
			ft_putstr("pa\n");
		}
		else if (!(smaller_than_median(b, median, count)))
			break ;
	}
	while (b->sub_lst[b->start] && --count[0] >= 0)
	{
		rev_rotate(&b->head, &b->tail);
		// ft_strcat(command, "rrb\n");
		ft_putstr("rrb\n");
	}
}

/*
**Similar to the situation of stack A, however this time
**the three lowest values are left behind on stack B,
**this function sorts those three values in descending order.
*/

static void	operations_stack_b(t_stack *a, t_stack *b)
{
	if (b->head->value > a->head->value)
	{
		while (!(b->head->next->value > b->head->next->next->value
				&& b->head->value > b->head->next->next->value))
		{
			if (b->head->next->value < b->head->next->next->value
				&& b->head->next->value < b->head->value)
			{
				rev_rotate(&b->head, &b->tail);
				// ft_strcat(command, "rrb\n");
				ft_putstr("rrb\n");
			}
			else
			{
				rotate(&b->head, &b->tail);
				// ft_strcat(command, "rb\n");
				ft_putstr("rb\n");
			}
		}
		if (b->head->next->value > b->head->value)
		{
			if (a->head->next->value < a->head->value)
			{
				swap(&a->head);
				swap(&b->head);
				// ft_strcat(command, "ss\n");
				ft_putstr("ss\n");
			}
			else
			{
				swap(&b->head);
				// ft_strcat(command, "sb\n");
				ft_putstr("sb\n");
			}
		}
	}
}

/*
**This function will execute moves on stack B.
*/

void		moves_on_stack_b(t_stack *a, t_stack *b, int count)
{
	if (b->start)
		b->start--;
	if (count == 1 || !count)
		return ;
	if (count == 2)
	{
		if (b->head->next && b->head->next->value > b->head->value)
		{
			if (a->head->next && (a->head->next->value < a->head->value))
			{
				swap(&a->head);
				swap(&b->head);
				// ft_strcat(command, "ss\n");
				ft_putstr("ss\n");
			}
			else
			{
				swap(&b->head);
				// ft_strcat(command, "sb\n");
				ft_putstr("sb\n");
			}
		}
		return ;
	}
	operations_stack_b(a, b);
}
