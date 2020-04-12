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

int		split_stack_a(t_stack *a, t_stack *b, t_list **command)
{
	int		count;
	long	median;
	char	temp[a->argc * 4];

	temp[0] = '\0';
	count = get_count(a);
	median = NO_MEDIAN;
	if (count <= 11 && count > 2)
		median = special_median_a(a);
	else if (count > 11)
		median = get_true_median(a);
	if (median != NO_MEDIAN)
		split_a(a, b, (int)median, temp);
	else
		sort_a(a, count, temp);
	if (temp[0])
		ft_lstaddend(command, ft_lstnew_str(temp));
	if (median == NO_MEDIAN)
		a->p[++(a->start)] = a->head;
	return ((median == NO_MEDIAN) ? 1 : 0);
}

int		sorted(t_stack *a)
{
	t_lst	*temp;

	temp = a->head;
	while (temp)
	{
		if (temp->next && temp->next->n < temp->n)
			return (0);
		temp = temp->next;
		if (temp == a->p[a->start])
			break ;
	}
	return (1);
}

void	push_b(t_stack *b, t_stack *a, int count, char *temp)
{
	int i;

	i = 0;
	count = (count == -1) ? 3 : count;
	while (i++ < count)
	{
		push(&b->head, &a->head, &a->tail);
		ft_strcat(temp, "pa\n");
	}
}

void	b_to_a(t_stack *a, t_stack *b, t_list **command)
{
	int		count;
	long	median;
	char	temp[a->argc * 4];

	temp[0] = '\0';
	count = get_count(b);
	median = NO_MEDIAN;
	if (count <= 6 && count > 2)
		median = special_median_b(b);
	else if (count > 6)
		median = get_true_median(b);
	if (median != NO_MEDIAN)
		split_b(a, b, (int)median, temp);
	else
		sort_b(b, count, temp);
	if (median == NO_MEDIAN)
		push_b(b, a, count, temp);
	if (temp[0])
		ft_lstaddend(command, ft_lstnew_str(temp));
}

t_list	*solver(t_stack *a, t_stack *b)
{
	t_list	*command;
	int		ret;
	int		sort;

	command = ft_lstnew((void *)"\0", 1);
	while (!(sort = sorted(a)) || b->head != NULL)
	{
		if (!sort)
		{
			while ((ret = split_stack_a(a, b, &command)) == 0)
				;
			if (ret == -1)
				exit(1);
		}
		else
			a->p[++(a->start)] = a->head;
		b_to_a(a, b, &command);
	}
	return (command);
}
