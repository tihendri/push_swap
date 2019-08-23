/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:05:43 by tihendri          #+#    #+#             */
/*   Updated: 2019/08/23 10:48:41 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_exit(t_stack *a, t_stack *b, int ok)
{
	t_lst	*tmp;

	while (a->head)
	{
		tmp = a->head;
		a->head = a->head->next;
		free(tmp);
	}
	while (b->head)
	{
		tmp = b->head;
		b->head = b->head->next;
		free(tmp);
	}
	if (ok)
		ft_putstr("OK\n");
	else if (!ok)
		ft_putstr("KO\n");
	exit(1);
}

int		check_a(t_stack *a)
{
	t_lst	*tmp;

	tmp = a->head;
	while (tmp->next != NULL)
	{
		if (tmp->next->n < tmp->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*l;

	if (ac < 2)
		return (0);
	build_stack(&a, &b, av, ac);
	while (get_next_line(0, &l) > 0)
	{
		if (!ft_strcmp(l, "sa") || !ft_strcmp(l, "sb") || !ft_strcmp(l, "ss"))
			swapper(l, &a, &b);
		else if (!ft_strcmp(l, "pa"))
			push(&b.head, &a.head, &a.tail);
		else if (!ft_strcmp(l, "pb"))
			push(&a.head, &b.head, &b.tail);
		else if (!ft_strcmp(l, "ra") || !ft_strcmp(l, "rb") || !ft_strcmp(l, "rr"))
			rotater(l, &a, &b);
		else if (!ft_strcmp(l, "rra") || !ft_strcmp(l, "rrb") || !ft_strcmp(l, "rrr"))
			rev_rotater(l, &a, &b);
		else
			print_exit(&a, &b, 0);
		free(l);
	}
	if (!check_a(&a) || b.head)
		print_exit(&a, &b, 0);
	print_exit(&a, &b, 1);
}
