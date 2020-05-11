/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:27:15 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 22:56:03 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**Used almost everywhere there's an error
*/

void	ft_puterror_exit(void)
{
	ft_putstr_fd("\e[1;31mError\n", 2);
	exit(EXIT_FAILURE);
}

/*
**Called in main function.
**Checks whether all numbers are sorted, then displays appropriate
**response.
*/

void		put_ok_ko(t_all *all)
{
	if (check_sorted(all) && (all->size_b == 0))
		ft_putstr_fd("\e[1;32mOK\n\e[0m", 1);
	else
		ft_putstr_fd("\e[1;31mKO\n\e[0m", 1);
}