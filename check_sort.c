/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:41:47 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/17 16:00:14 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_sort(t_all *all)
{
	int i;

	i = 0;
	while (i < all->size_a - 1)
	{
		if (all->int_stack_a[i] > all->int_stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
