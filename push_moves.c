/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:24:48 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 17:01:07 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_all *all)
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

void	pb(t_all *all)
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
