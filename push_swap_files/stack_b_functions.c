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

long		special_median_b(t_stack *b)
{
	t_lst	*temp;
	int		arr[7];
	int		i;
	int		j[2];

	temp = b->head;
	i = 0;
	while (temp != b->p[b->start])
	{
		arr[i++] = temp->value;
		temp = temp->next;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] > arr[j[1]])
			{
				arr[6] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[6];
			}
	}
	return ((!b->p[b->start]) ? arr[2] : arr[1]);
}

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

static int	smaller_than_median(t_stack *b, char *com, int med, int count[2])
{
	int		skips;
	t_lst	*temp;

	skips = 0;
	temp = b->head;
	while (temp != b->p[b->start] && temp->value <= med)
	{
		skips++;
		temp = temp->next;
	}
	if (temp == b->p[b->start])
		return (0);
	count[0] += skips;
	while (skips--)
	{
		rotate(&b->head, &b->tail);
		ft_strcat(com, "rb\n");
	}
	return (1);
}

/*
**This function will be the "driving force" of the operations
**for stack B, by continuously pushing to stack A if the number
**is higher than the median
*/

void		work_stack_b(t_stack *a, t_stack *b, int med, char *com)
{
	int		count[2];

	count[0] = 0;
	count[1] = 0;
	while (b->head != b->p[b->start])
	{
		if (b->head->value > med)
		{
			push(&b->head, &a->head, &a->tail);
			ft_strcat(com, "pa\n");
		}
		else if (!(smaller_than_median(b, com, med, count)))
			break ;
	}
	while (b->p[b->start] && --count[0] >= 0)
	{
		rev_rotate(&b->head, &b->tail);
		ft_strcat(com, "rrb\n");
	}
}

/*
**Similar to the situation of stack A, however this time
**the three lowest values are left behind on stack B,
**this function sorts those three values in descending order.
*/

static void	last_three_numbers_stack_b(t_stack *a, char *temp)
{
	while (!(a->head->next->value > a->head->next->next->value
	&& a->head->value > a->head->next->next->value))
	{
		if (a->head->next->value < a->head->next->next->value
		&& a->head->next->value < a->head->value)
		{
			rev_rotate(&a->head, &a->tail);
			ft_strcat(temp, "rrb\n");
		}
		else
		{
			rotate(&a->head, &a->tail);
			ft_strcat(temp, "rb\n");
		}
	}
	if (!(a->head->next->value > a->head->value))
		return ;
	swap(&a->head);
	ft_strcat(temp, "sb\n");
}

/*
**This function will sort/deal with the remaining three numbers
**after all the operations have been performed on the smaller
**numbers.
*/

void		sort_stack_b_last_three(t_stack *b, int count, char *temp)
{
	if (b->start)
		b->start--;
	if (count == 1 || !count)
		return ;
	if (count == 2)
	{
		if (b->head->next && b->head->next->value > b->head->value)
		{
			swap(&b->head);
			ft_strcat(temp, "sb\n");
		}
		return ;
	}
	last_three_numbers_stack_b(b, temp);
}
