/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:27:11 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 14:32:50 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_int(int *array, int c, int n)
{
	int i;

	i = -1;
	while (++i < n)
		if (array[i] == c)
			return (0);
	return (1);
}

void	check_duplicates(t_all *all)
{
	int i;

	i = -1;
	while (++i < all->size_a)
		if (check_int(all->int_stack_a, all->int_stack_a[i], i) == 0)
		{
			ft_putstr_fd("\e[31mError\n\e[0m", 2);
			exit(EXIT_FAILURE);
		}
}
