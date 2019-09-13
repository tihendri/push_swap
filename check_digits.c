/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:15:10 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 13:16:31 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_digits(char *s)
{
	int i;

	i = -1;
	while (++i < (int)ft_strlen(s))
		if (s[i] != '+' && s[i] != '-' && !ft_isdigit(s[i]))
		{
			ft_putstr_fd("\e[31mError\n\e[0m", 2);
			exit(EXIT_FAILURE);
		}
	i = -1;
	while (++i < (int)ft_strlen(s))
		if ((s[i] == '+' || s[i] == '-') && !ft_isdigit(s[i + 1]))
			return (0);
	return (1);
}
