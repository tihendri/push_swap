/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:30:52 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 13:33:21 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_all *all)
{
	int i;
	int tmp;

	i = -1;
	tmp = all->int_stack_a[0];
	while (++i < all->size_a - 1)
		all->int_stack_a[i] = all->int_stack_a[i + 1];
	all->int_stack_a[i] = tmp;
}

void	rb(t_all *all)
{
	int i;
	int tmp;

	i = -1;
	tmp = all->int_stack_b[0];
	while (++i < all->size_b - 1)
		all->int_stack_b[i] = all->int_stack_b[i + 1];
	all->int_stack_b[i] = tmp;
}

void	rr(t_all *all)
{
	ra(all);
	// rb(all);
}
