/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:16:17 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 20:50:15 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_count(t_stack *stack)
{
	int		count;
	t_lst	*temp;

	temp = stack->head;
	count = 0;
	while (temp != stack->sub_lst[stack->start] && count < 10)
	{
		count++;
		temp = temp->next;
	}
	if (!stack->sub_lst[stack->start] && count == 3)
		return (-1);
	return (count);
}

/*
**This function is used to get the median of the stack when there's fewer
**arguments on stack A.
**This heps with effieciency by lowering the amount of moves made when
**the arguments are fewer.
**This function is specifically created for the evaluation of this project.
*/

long	low_args_median_a(t_stack *a)
{
	t_lst	*temp;
	int		arr[8];
	int		i;
	int		j[2];

	temp = a->head;
	i = 0;
	while (temp != a->sub_lst[a->start])
	{
		arr[i++] = temp->value;
		temp = temp->next;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] < arr[j[1]])
			{
				arr[7] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[7];
			}
	}
	return ((!a->sub_lst[a->start]) ? arr[3] : arr[2]);
}

/*
**This function is used to get the median of the stack when there's fewer
**arguments on stack B.
**This heps with effieciency by lowering the amount of moves made when
**the arguments are fewer.
**This function is specifically created for the evaluation of this project.
*/

long	low_args_median_b(t_stack *b)
{
	t_lst	*temp;
	int		arr[5];
	int		i;
	int		j[2];

	temp = b->head;
	i = 0;
	while (temp != b->sub_lst[b->start])
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
				arr[4] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[4];
			}
	}
	return ((!b->sub_lst[b->start]) ? arr[2] : arr[1]);
}

/*
**Finds the actual median of the number set, in the stack.
**This is the original median-finding function used in my
**algorithm.
*/

int		real_median(t_stack *stack)
{
	t_lst	*temp;
	int		arr[stack->argc + 1];
	int		i;
	int		j[2];

	temp = stack->head;
	i = 0;
	while (temp != stack->sub_lst[stack->start])
	{
		arr[i++] = temp->value;
		temp = temp->next;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] < arr[j[1]])
			{
				arr[stack->argc] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[stack->argc];
			}
	}
	return (arr[i / 2]);
}
