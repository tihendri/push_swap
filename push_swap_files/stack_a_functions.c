/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:18:38 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 23:18:27 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**This function will check the values on the stack:
**if the number is larger than the median, rotate it to the back
**of the stack.
**This is because we want to get the three biggest numbers
**remaining on stack A.
**This function works opporsite to the "num_smaller_than_median"
**function in stack_b_functions.c file
*/

static int	over_median(t_stack *a, char *command, int median, int *places)
{
	t_lst	*temp;
	int		counter;

	temp = a->head;
	counter = 0;
	while (temp != a->sub_lst[a->start] && temp->value > median)
	{
		counter++;
		temp = temp->next;
	}
	if (temp == a->sub_lst[a->start])
		return (0);
	*places = *places + counter;
	while (counter--)
	{
		rotate(&a->head, &a->tail);
		ft_strcat(command, "ra\n");
	}
	return (1);
}

/*
**This function will be the "driving force" of the operations
**for stack B, by continuously pushing to stack A if the number
**on stack A falls below median
*/

void		work_stack_a(t_stack *a, t_stack *b, int median, char *command)
{
	int		places_moved;

	places_moved = 0;
	if (b->head)
		b->sub_lst[++(b->start)] = b->head;
	while (a->head != a->sub_lst[a->start])
	{
		if (a->head->value <= median)
		{
			push(&a->head, &b->head, &b->tail);
			ft_strcat(command, "pb\n");
		}
		else if (!(over_median(a, command, median, &places_moved)))
			break ;
	}
	while (a->sub_lst[a->start] && --places_moved >= 0)
	{
		rev_rotate(&a->head, &a->tail);
		ft_strcat(command, "rra\n");
	}
}

/*
**After all operations pushing to stack B,
**the three highest values are left behind on stack A,
**this function sorts those three values.
*/

static void	operations_stack_a(t_stack *a, char *command)
{
	while (!(a->head->next->value < a->head->next->next->value
			&& a->head->value < a->head->next->next->value))
	{
		if (a->head->next->value > a->head->next->next->value
			&& a->head->next->value > a->head->value)
		{
			rev_rotate(&a->head, &a->tail);
			ft_strcat(command, "rra\n");
		}
		else
		{
			rotate(&a->head, &a->tail);
			ft_strcat(command, "ra\n");
		}
	}
	if (!(a->head->next->value < a->head->value))
		return ;
	swap(&a->head);
	ft_strcat(command, "sa\n");
}

/*
**This function is respomsible for executing the required move
**on stack A.
*/

void		moves_on_stack_a(t_stack *a, t_stack *b, int count, char *command)
{
	if (count == 1)
		return ;
	if (count == 2)
	{
		if (a->head->next->value < a->head->value)
		{
			if (b->head && b->head->next && (b->head->next->value > b->head->value))
			{
				swap(&a->head);
				swap(&b->head);
				ft_strcat(command, "ss\n");
			}
			else
			{
				swap(&a->head);
				ft_strcat(command, "sa\n");
			}
		}
		return ;
	}
	operations_stack_a(a, command);
}
