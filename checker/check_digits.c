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
	long n;

	i = 0;
	if (s[i] >= 48 && s[i] <= 57)
	{
		while (i < (int)ft_strlen(s))
		{
			n = ft_atol(&s[i]);
			if (n < 2147483647)
				n = ft_atoi(&s[i]);
			else
				ft_puterror_exit();
			if (s[i] != '+' && s[i] != '-' && !ft_isdigit(s[i]))
				ft_puterror_exit();
			i++;
		}
	}
	else
		ft_puterror_exit();
	i = -1;
	while (++i < (int)ft_strlen(s))
		if ((s[i] == '+' || s[i] == '-') && !ft_isdigit(s[i + 1]))
			return (0);
	return (1);
}
