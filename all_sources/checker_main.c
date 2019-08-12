/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:05:43 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/26 13:43:30 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
**This function puts the the message ok or ko.
**if int ok is 0 (false), display KO.
**if int ok is 1 (true), display OK.
**exit with successful/unsuccessful termination of program.
*/

void	display_finish(t_stack *a, t_stack *b, int ok)
{
	t_lst	*temp;

	while (a->head)
	{
		temp = a->head;
		a->head = a->head->next;
		free(temp);
	}
	while (b->head)
	{
		temp = b->head;
		b->head = b->head->next;
		free(temp);
	}
	if (ok)
	{
		ft_putstr("OK\n");
		exit(0);
	}
	if (!ok)
	{
		ft_putstr("KO\n");
		exit(1);
	}
}

/*
**This function checks the stack is sorted.
*/

int		check_stack(t_stack *stack)
{
	t_lst	*temp;

	temp = stack->head;
	while (temp->next != NULL)
	{
		if (temp->next->n < temp->n)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/*
**This is the main function of checker.
*/

int		main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*l;

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
			display_finish(&a, &b, 0);
		free(l);
	}
	if (!check_stack(&a) || b.head)
		display_finish(&a, &b, 0);
	display_finish(&a, &b, 1);
}
