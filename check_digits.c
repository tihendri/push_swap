/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:15:10 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/19 23:31:15 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_digits(char *s)
{
	int i;
	int n;

	i = 0;
	n = ft_atoi(&s[i]);
	while (i < (int)ft_strlen(s))
	{
		n = ft_atoi(&s[i]);
		if (s[i] != '+' && s[i] != '-' &&
				!ft_isdigit(s[i]) && ft_int_too_big(n))
		{
			ft_putstr_fd("\e[31mError\n\e[0m", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = -1;
	while (++i < (int)ft_strlen(s))
		if ((s[i] == '+' || s[i] == '-') && !ft_isdigit(s[i + 1]))
			return (0);
	return (1);
}
