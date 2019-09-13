/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:22:19 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 14:24:30 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_all *all)
{
	int i;

	i = all->size_a;
	while (--i > 0)
		swap(&all->int_stack_a[i], &all->int_stack_a[i - 1]);
}

void	rrb(t_all *all)
{
	int i;

	i = all->size_b;
	while (--i > 0)
		swap(&all->int_stack_b[i], &all->int_stack_b[i - 1]);
}

void	rrr(t_all *all)
{
	rra(all);
	rrb(all);
}
