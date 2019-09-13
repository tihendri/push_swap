/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:53:04 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 23:06:08 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <limits.h>

/*
**void	print_stacks(t_all *all)
**{
**	fprintf(stderr, "\e[34mSize A = %d ", all->size_a);
**	fprintf(stderr, "\e[31mSTACK A = ");
**	for(int i = 0; i < all->size_a; i++)
**		fprintf(stderr, "%d ", all->int_stack_a[i]);
**	fprintf(stderr, "\e[0m\n");
**	fprintf(stderr, "\e[34mSize B = %d ", all->size_b);
**	fprintf(stderr, "\e[32mSTACK B = ");
**	for(int i = 0; i < all->size_b; i++)
**		fprintf(stderr, "%d ", all->int_stack_b[i]);
**	fprintf(stderr, "\e[0m\n");
**}
*/

void		put_ok_ko(t_all *all)
{
	if (check_ascii(all))
		ft_putstr_fd("\e[32mOK\n\e[0m", 2);
	else
		ft_putstr_fd("\e[31mko\n\e[0m", 2);
}

char		**join_arguments(char **av)
{
	int		i;
	char	**array;
	char	**split;

	i = -1;
	array = (char **)malloc(sizeof(char *));
	*array = NULL;
	while (av[++i] != NULL)
	{
		if (!ft_strcmp(av[i], "-v") || !ft_strcmp(av[i], "-c") ||
		!ft_strcmp(av[i], "-d"))
			continue ;
		split = ft_strsplit(av[i], ' ');
		array = ft_array_join(array, split);
	}
	return (array);
}

int			main(int ac, char **av)
{
	t_all	*initialize_struct();
	void	fill_stack(t_all *all);
	t_all	*all;

	(void)ac;
	all = initialize_struct();
	all->args = join_arguments(av + 1);
	error_check(all);
	all->size = ft_array_size(all->args);
	all->size_a = all->size;
	fill_stack(all);
//	print_stacks(all);
	check_duplicates(all);
	if (check_ascii(all))
		return (0);
	while (get_next_line(0, &all->line) > 0)
	{
		check_moves(all, all->line);
//		print_stacks(all);
		if (all->line)
			ft_strdel(&all->line);
	}
	put_ok_ko(all);
	free_all(all);
	return (0);
}
