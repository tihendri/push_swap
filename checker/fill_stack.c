/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:12:54 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 22:57:41 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	fill_stack(t_all *all)
{
	int i;

	i = 0;
	all->int_stack_a = (int *)malloc(sizeof(int ) * all->size);
	all->int_stack_b = (int *)malloc(sizeof(int ) * all->size + 2);
	while (i < all->size)
	{
		all->int_stack_a[i] = ft_atoi(all->args[i]);
		all->int_stack_b++;
		i++;
	}
	all->int_stack_b++;
}
