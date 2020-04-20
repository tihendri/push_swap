/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:16:17 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 20:50:15 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_count(t_stack *s)
{
	int		count;
	t_lst	*temp;

	temp = s->head;
	count = 0;
	while (temp != s->p[s->start] && count < 12)
	{
		count++;
		temp = temp->next;
	}
	if (!s->p[s->start] && count == 3)
		return (-1);
	return (count);
}

/*
**Finds wherever i is and splits the total in half.
**Uses a "ft_swap" kind of function at lines 58-60.
*/

int	real_median(t_stack *a)
{
	t_lst	*temp;
	int		arr[a->argc + 1];
	int		i;
	int		j[2];

	temp = a->head;
	i = 0;
	while (temp != a->p[a->start])
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
				arr[a->argc] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[a->argc];
			}
	}
	return (arr[i / 2]);
}
