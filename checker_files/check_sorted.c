/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:41:47 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/19 23:21:05 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**Called by function "put_ok_ko"
**Checks whether each value is smaller than the next.
**This function is only used on stack A because all the values need to be
**sorted on stack A and stack B needs to be empty.
*/

int	check_sorted(t_all *all)
{
	unsigned int i;

	i = 0;
	while (i < all->size_a - 1)
	{
		if (all->int_stack_a[i] > all->int_stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
