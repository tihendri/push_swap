/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:53:04 by tihendri          #+#    #+#             */
/*   Updated: 2019/11/21 14:39:06 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**this is a bonus function
*/

void	visualize_stacks(t_all *all)
{
	fprintf(stderr, "Size A = %d ", all->size_a);
	fprintf(stderr, "STACK A = ");
	for(int i = 0; i < all->size_a; i++)
		fprintf(stderr, "%d ", all->int_stack_a[i]);
	fprintf(stderr, "\n");
	fprintf(stderr, "Size B = %d ", all->size_b);
	fprintf(stderr, "STACK B = ");
	for(int i = 0; i < all->size_b; i++)
		fprintf(stderr, "%d ", all->int_stack_b[i]);
	fprintf(stderr, "\n");
}

void	visualize_stacks_colour(t_all *all)
{
	fprintf(stderr, "\e[34mSize A = %d ", all->size_a);
	fprintf(stderr, "\e[31mSTACK A = ");
	for(int i = 0; i < all->size_a; i++)
		fprintf(stderr, "%d ", all->int_stack_a[i]);
	fprintf(stderr, "\e[0m\n");
	fprintf(stderr, "\e[34mSize B = %d ", all->size_b);
	fprintf(stderr, "\e[32mSTACK B = ");
	for(int i = 0; i < all->size_b; i++)
		fprintf(stderr, "%d ", all->int_stack_b[i]);
	fprintf(stderr, "\e[0m\n");
}

void	print_stacks_bonus(t_all *all)
{
	// av = NULL;
	// if (ft_strequ(av[2], "-v"))
		visualize_stacks(all);
	// else if (ft_strequ(av[2], "-c"))
		// visualize_stacks_colour(all);
	// else
	// 	ft_puterror_exit();
}

void		put_ok_ko(t_all *all)
{
	if (check_sorted(all) && (all->size_b == 0))
		ft_putstr_fd("\e[32mOK\n\e[0m", 2);
	else
		ft_putstr_fd("\e[31mKO\n\e[0m", 2);
}

// char		**join_arguments(char **av)
// {
	// int		i;
	// char	**array;
	// char	**split;

	// i = -1;
	// array = (char **)malloc(sizeof(char *));
	// *array = NULL;
	// while (av[++i] != NULL)
	// {
	// 	// if (!ft_strcmp(av[i], "-v") || !ft_strcmp(av[i], "-c") ||
	// 	// !ft_strcmp(av[i], "-d"))
	// 	// 	continue ;
	// 	// else
	// 	// 	visualize_stacks()
	// 	split = ft_strsplit(av[i], ' ');
	// 	array = ft_array_join(array, split);
	// }
	// return (array);
// }

void	populate(int ac, char **av, t_all *all)
{
	int i;

	i = 0;
	if (ac == 2 || (ac == 3 && ft_strequ(av[2], "-v")) || (ac == 3 && ft_strequ(av[2], "-c")))
	{
		all->args = ft_strsplit(av[1], ' ');//join_arguments(&av[1]);
		check_duplicates(all->args);
		error_check(all);
	}
	else
	{
		all->args = av + 1;
		check_duplicates(av + 1);
		error_check(all);
	}
	all->size = ft_array_size(all->args);
	all->size_a = all->size;
	fill_stack(all);
}

int		main(int ac, char **av)
{
	t_all	*initialize_struct();
	void	fill_stack(t_all *all);
	t_all	*all;

	if (ac < 2)
		return (0);
	all = initialize_struct();
	populate(ac, av, all);
	// if (ac == 3 && (ft_strequ(av[2], "-v") || ft_strequ(av[2], "-v")))
		print_stacks_bonus(all);
	while (get_next_line(0, &all->line) > 0)
	{
		check_moves(all, all->line);
		// if (ac == 3 && (ft_strequ(av[2], "-v") || ft_strequ(av[2], "-v")))
			print_stacks_bonus(all);
		if (all->line)
			ft_strdel(&all->line);
	}
	put_ok_ko(all);
	return (0);
}