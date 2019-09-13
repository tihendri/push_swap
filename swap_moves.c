/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:55:23 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 13:34:08 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_all *all)
{
	swap(&all->int_stack_a[0], &all->int_stack_a[1]);
}

void	sb(t_all *all)
{
	swap(&all->int_stack_b[0], &all->int_stack_b[1]);
}

void	ss(t_all *all)
{
	sa(all);
	sb(all);
}
