/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:55:23 by tihendri          #+#    #+#             */
/*   Updated: 2019/11/17 13:34:08 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**To swap two values, or rather their memory addresses, to be more specific.
*/

static void	swap(unsigned int *a, unsigned int *b)
{
	unsigned int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
**Swaps the first two values on stack a. MAXINT is used so that the program
**interprets "0" (zero) as a workable value instead of an indicator of an
**empty address, by comparing the value at the address (which could be zero)
**to an actual value.
*/

void		sa(t_all *all)
{
	if (all->int_stack_a[0] < MAXINT)
	{
		if (all->int_stack_a[1] < MAXINT)
		{
			swap(&all->int_stack_a[0], &all->int_stack_a[1]);
		}
	}
}

void		sb(t_all *all)
{
	if (all->int_stack_b[0] < MAXINT)
	{
		if (all->int_stack_b[1] < MAXINT)
		{
			swap(&all->int_stack_b[0], &all->int_stack_b[1]);
		}
	}
}

void		ss(t_all *all)
{
	sa(all);
	sb(all);
}

/*
**Moves the address of the first value to the last value on the stack, which
**in turn shifts every other value's address one space down, making the initial
**second value first, third value is now second, etc.
**Refer to swap_moves.c for explanation on why I used MAXINT.
*/

void		ra(t_all *all)
{
	unsigned int i;
	unsigned int tmp;

	i = -1;
	tmp = all->int_stack_a[0];
	if (all->int_stack_a[0] < MAXINT)
	{
		if (all->int_stack_a[1] < MAXINT)
		{
			while (++i < all->size_a - 1)
				all->int_stack_a[i] = all->int_stack_a[i + 1];
			all->int_stack_a[i] = tmp;
		}
	}
}

void		rb(t_all *all)
{
	unsigned int i;
	unsigned int tmp;

	i = -1;
	tmp = all->int_stack_b[0];
	if (all->int_stack_b[0] < MAXINT)
	{
		if (all->int_stack_b[1] < MAXINT)
		{
			while (++i < all->size_b - 1)
				all->int_stack_b[i] = all->int_stack_b[i + 1];
			all->int_stack_b[i] = tmp;
		}
	}
}

void		rr(t_all *all)
{
	ra(all);
	rb(all);
}

/*
**Moves the address of the last value to the first value on the stack, which
**in turn shifts every other value's address one space up, making the initial
**first value second, second value is now third, etc.
**Refer to swap_moves.c for explanation on why I used MAXINT.
*/

void		rra(t_all *all)
{
	unsigned int i;
	
	if (all->int_stack_a[0] < MAXINT)
	{
		if (all->int_stack_a[1] < MAXINT)
		{
			i = all->size_a;
			while (--i > 0)
				swap(&all->int_stack_a[i], &all->int_stack_a[i - 1]);
		}
	}
}

void		rrb(t_all *all)
{
	unsigned int i;

	if (all->int_stack_b[0] < MAXINT)
	{
		if (all->int_stack_b[1] < MAXINT)
		{
			i = all->size_b;
			while (--i > 0)
				swap(&all->int_stack_b[i], &all->int_stack_b[i - 1]);
		}
	}
}

void		rrr(t_all *all)
{
	rra(all);
	rrb(all);
}

/*
**Pushes the first value from whichever stack to the other stack, and places
**the address of that value first on the receiving stack.
**The sizes and array totals of the stacks are adjusted accordingly to avoid
**any overlapping of memory usage and unwanted errors,
**such as segmentation faults.
*/

void		pa(t_all *all)
{
	if (all->size_b > 0)
	{
		all->int_stack_a--;
		all->size_a++;
		all->size_b--;
		*all->int_stack_a = all->int_stack_b[0];
		all->int_stack_b++;
	}
}

void		pb(t_all *all)
{
	if (all->size_a > 0)
	{
		all->int_stack_b--;
		all->size_b++;
		all->size_a--;
		*all->int_stack_b = all->int_stack_a[0];
		all->int_stack_a++;
	}
}