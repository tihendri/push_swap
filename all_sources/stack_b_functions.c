/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:17:30 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/25 17:14:57 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	special_median_b(t_stack *b)
{
	t_lst	*temp;
	int		arr[7];
	int		i;
	int		j[2];

	temp = b->head;
	i = 0;
	while (temp != b->p[b->start])
	{
		arr[i++] = temp->n;
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
**works with lower stack_b size
*/

int		low_b(t_stack *b, char *com, int med, int count[2])
{
	int		skips;
	t_lst	*temp;

	skips = 0;
	temp = b->head;
	while (temp != b->p[b->start] && temp->n <= med)
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
**splits stack_b by median/middle
*/

void	split_b(t_stack *a, t_stack *b, int med, char *com)
{
	int		count[2];

	count[0] = 0;
	count[1] = 0;
	while (b->head != b->p[b->start])
	{
		if (b->head->n > med)
		{
			push(&b->head, &a->head, &a->tail);
			ft_strcat(com, "pa\n");
		}
		else if (!(low_b(b, com, med, count)))
			break ;
	}
	while (b->p[b->start] && --count[0] >= 0)
	{
		rev_rotate(&b->head, &b->tail);
		ft_strcat(com, "rrb\n");
	}
}

void	three_caseb(t_stack *a, char *temp)
{
	while (!(a->head->next->n > a->head->next->next->n
	&& a->head->n > a->head->next->next->n))
	{
		if (a->head->next->n < a->head->next->next->n
		&& a->head->next->n < a->head->n)
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
	if (!(a->head->next->n > a->head->n))
		return ;
	swap(&a->head);
	ft_strcat(temp, "sb\n");
}

void	sort_b(t_stack *b, int count, char *temp)
{
	if (b->start)
		b->start--;
	if (count == 1 || !count)
		return ;
	if (count == 2)
	{
		if (b->head->next && b->head->next->n > b->head->n)
		{
			swap(&b->head);
			ft_strcat(temp, "sb\n");
		}
		return ;
	}
	three_caseb(b, temp);
}
