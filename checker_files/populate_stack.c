/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:53:04 by tihendri          #+#    #+#             */
/*   Updated: 2019/11/21 14:39:06 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**Used to put all the received values into the stack. The values are put in
**stack A, however stack B is still expanded so that there is enough space on
**stack B to receive all the values if necessary.
**ft_atoi converts the arguments to integer, regardless of whether they're
**integers already.
*/

static void	fill_stack(t_all *all)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	all->int_stack_a = (unsigned int *)malloc(sizeof(int ) * all->size);
	all->int_stack_b = (unsigned int *)malloc(sizeof(int ) * all->size);
	while (i < all->size)
	{
		all->int_stack_a[i] = ft_atoi(all->args[i]);
		all->int_stack_b[j] = 0;
		i++;
		j++;
	}
}

/*
**Called in main function.
**This function is used to populate the stack with the values parsed,
**after vigorous sifting and validation on the values as required by
**the program to run,
**error_check is used for validation of values and fill_stack is then
**used after all the validation is successful to populate the stack.
*/

void		populate_stack(int ac, char **av, t_all *all)
{
	if (ac == 2 || (ac == 3 && ft_strequ(av[2], "-v")) ||
		(ac == 3 && ft_strequ(av[2], "-c")))
	{
		all->token = TOKEN_STR;
		all->args = ft_strsplit(av[1], ' ');
		error_check(all);
	}
	else
	{
		all->token = TOKEN_INT;
		all->args = av + 1;
		error_check(all);
	}
	all->size = ft_array_size(all->args);
	all->size_a = all->size;
	fill_stack(all);
}