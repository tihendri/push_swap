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
**This function is used to get the median of the stack when there's fewer
**arguments.
**This heps with effieciency by lowering the amount of moves made when
**the arguments are fewer.
**This function is specifically created for the evaluation of this project.
*/

long		low_args_median_a(t_stack *a)
{
	t_lst	*temp;
	int		arr[12];
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
				arr[11] = arr[j[1]];
				arr[j[1]] = arr[j[0]];
				arr[j[0]] = arr[11];
			}
	}
	return ((!a->p[a->start]) ? arr[3] : arr[2]);
}

/*
**This function will check the values on the stack:
**if the number is larger than the median, rotate it to the back
**of the stack.
**This is because we want to get the three biggest numbers
**remaining on stack A.
**This function works opporsite to the "num_smaller_than_median"
**function in stack_b_functions.c file
*/

static int	over_median(t_stack *a, char *command, int median, int *t_rewind)
{
	t_lst	*temp;
	int		counter;

	temp = a->head;
	counter = 0;
	while (temp != a->p[a->start] && temp->value > median)
	{
		counter++;
		temp = temp->next;
	}
	if (temp == a->p[a->start])
		return (0);
	*t_rewind = *t_rewind + counter;
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
	int		rewind;

	rewind = 0;
	if (b->head)
		b->p[++(b->start)] = b->head;
	while (a->head != a->p[a->start])
	{
		if (a->head->value <= median)
		{
			push(&a->head, &b->head, &b->tail);
			ft_strcat(command, "pb\n");
		}
		else if (!(over_median(a, command, median, &rewind)))
			break ;
	}
	while (a->p[a->start] && --rewind >= 0)
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

static void	last_three_numbers_stack_a(t_stack *a, char *temp)
{
	while (!(a->head->next->value < a->head->next->next->value
	&& a->head->value < a->head->next->next->value))
	{
		if (a->head->next->value > a->head->next->next->value
		&& a->head->next->value > a->head->value)
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
	if (!(a->head->next->value < a->head->value))
		return ;
	swap(&a->head);
	ft_strcat(temp, "sa\n");
}

/*
**This function will sort/deal with the remaining three numbers
**after all the operations have been performed on the smaller
**numbers.
*/

void		sort_stack_a_last_three(t_stack *a, int count, char *temp)
{
	if (count == 1)
		return ;
	if (count == 2)
	{
		if (a->head->next->value < a->head->value)
		{
			swap(&a->head);
			ft_strcat(temp, "sa\n");
		}
		return ;
	}
	last_three_numbers_stack_a(a, temp);
}
