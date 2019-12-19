/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:29:18 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 22:56:03 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_puterror_exit(void)
{
	ft_putstr_fd("\e[31mError\n", 2);
	exit(EXIT_FAILURE);
}

void	error_check(t_all *all)
{
	int i;

	i = -1;
	while (all->args[++i])
	{
		if (!check_digits(all->args[i]))
		{
			ft_array_free(&all->args);
			free(all);
			ft_puterror_exit();
		}
	}
}
