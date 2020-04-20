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

int			main(int ac, char **av)
{
	t_all	*all;

	if (ac < 2)
		return (0);
	all = initialize_struct();
	populate_stack(ac, av, all);
	if (ac == 3 && (ft_strequ(av[2], "-v") ||
		ft_strequ(av[2], "-c")))
		print_stacks_bonus(all, av);
	while (get_next_line(0, &all->line))
	{
		exec_moves(all, all->line);
		if (ac == 3 && (ft_strequ(av[2], "-v") ||
			ft_strequ(av[2], "-c")))
			print_stacks_bonus(all, av);
		if (all->line)
			ft_strdel(&all->line);
	}
	put_ok_ko(all);
	free(all);
	return (0);
}