/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:18:38 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/25 09:51:29 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	special_median_a(t_stack *a)
{
	t_lst	*temp;
	int		arr[12];
	int		i;
	int		j[2];

	temp = a->head;
	i = 0;
	while (temp != a->p[a->start])
	{
		arr[i++] = temp->n;
		temp = temp->next;
	}
	j[0] = -1;
	while (j[0]++ < i)
	{
		j[1] = j[0];
		while (++j[1] < i)
			if (arr[j[0]] < arr[j[1]])
			{
				arr[11] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[11];
			}
	}
	return ((!a->p[a->start]) ? arr[3] : arr[2]);
}

/*
**work with larger stack
*/

int		big_a(t_stack *a, char *com, int med, int *t_rewind)
{
	int		skips;
	t_lst	*temp;

	skips = 0;
	temp = a->head;
	while (temp != a->p[a->start] && temp->n > med)
	{
		skips++;
		temp = temp->next;
	}
	if (temp == a->p[a->start])
		return (0);
	*t_rewind = *t_rewind + skips;
	while (skips--)
	{
		rotate(&a->head, &a->tail);
		ft_strcat(com, "ra\n");
	}
	return (1);
}

/*
**splits stack_a at the median/middle
*/

void	split_a(t_stack *a, t_stack *b, int med, char *com)
{
	int		rewind;

	rewind = 0;
	if (b->head)
		b->p[++(b->start)] = b->head;
	while (a->head != a->p[a->start])
	{
		if (a->head->n <= med)
		{
			push(&a->head, &b->head, &b->tail);
			ft_strcat(com, "pb\n");
		}
		else if (!(big_a(a, com, med, &rewind)))
			break ;
	}
	while (a->p[a->start] && --rewind >= 0)
	{
		rev_rotate(&a->head, &a->tail);
		ft_strcat(com, "rra\n");
	}
}

void	three_case(t_stack *a, char *temp)
{
	while (!(a->head->next->n < a->head->next->next->n
	&& a->head->n < a->head->next->next->n))
	{
		if (a->head->next->n > a->head->next->next->n
		&& a->head->next->n > a->head->n)
		{
			rev_rotate(&a->head, &a->tail);
			ft_strcat(temp, "rra\n");
		}
		else
		{
			rotate(&a->head, &a->tail);
			ft_strcat(temp, "ra\n");
		}
	}
	if (!(a->head->next->n < a->head->n))
		return ;
	swap(&a->head);
	ft_strcat(temp, "sa\n");
}

void	sort_a(t_stack *a, int count, char *temp)
{
	if (count == 1)
		return ;
	if (count == 2)
	{
		if (a->head->next->n < a->head->n)
		{
			swap(&a->head);
			ft_strcat(temp, "sa\n");
		}
		return ;
	}
	three_case(a, temp);
}
