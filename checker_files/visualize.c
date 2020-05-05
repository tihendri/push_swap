/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:53:04 by tihendri          #+#    #+#             */
/*   Updated: 2019/11/29 14:39:06 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**this is a bonus function, prints the stacks to the stdout or terminal.
*/

static void	visualize_stacks(t_all *all)
{
	unsigned int i_a;
	unsigned int i_b;

	i_a = 0;
	i_b = 0;
	ft_putstr("SIZE A = ");
	ft_putnbr(all->size_a);
	ft_putstr(" STACK A = ");
	while (i_a < all->size_a)
	{
		ft_putnbr(all->int_stack_a[i_a]);
		write(1, " ", 1);
		i_a++;
	}
	ft_putstr("\n");
	ft_putstr("SIZE B = ");
	ft_putnbr(all->size_b);
	ft_putstr(" STACK B = ");
	while (i_b < all->size_b)
	{
		ft_putnbr(all->int_stack_b[i_b]);
		write(1, " ", 1);
		i_b++;
	}
	ft_putstr("\n");
	ft_putstr("\n");
}

/*
**this is a bonus function, prints the stacks in colour to the stdout,
**or terminal.
*/

static void	visualize_stacks_colour(t_all *all)
{
	unsigned int i_a;
	unsigned int i_b;

	i_a = 0;
	i_b = 0;
	ft_putstr("\e[1;33mSIZE A = ");
	ft_putnbr(all->size_a);
	ft_putstr("\t|\e[1;32mSTACK A = ");
	while (i_a < all->size_a)
	{
		ft_putnbr(all->int_stack_a[i_a]);
		write(1, " ", 1);
		i_a++;
	}
	ft_putstr("\e[0m\n");
	ft_putstr("\e[1;33mSIZE B = ");
	ft_putnbr(all->size_b);
	ft_putstr("\t|\e[1;31mSTACK B = ");
	while (i_b < all->size_b)
	{
		ft_putnbr(all->int_stack_b[i_b]);
		write(1, " ", 1);
		i_b++;
	}
	ft_putstr("\e[0m\n");
	ft_putstr("\e[0m\n");
}

/*
**Called in main function
**For the flags of the program
*/

void		print_stacks_bonus(t_all *all, char **av)
{
	if (ft_strequ(av[2], "-v"))
		visualize_stacks(all);
	else if (ft_strequ(av[2], "-c"))
		visualize_stacks_colour(all);
}