/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:15:10 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/19 23:31:15 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**Used in function called "error_check" in the file error_check.c,
**in a while loop.
**This function checks if the values parsed are valid, per digit.
*/

static int	check_digits(char *s)
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
				return (0);
			if (s[i] != '+' && s[i] != '-' && !ft_isdigit(s[i]))
				return (0);
			i++;
		}
	}
	else
		return (0);
	i = -1;
	while (++i < (int)ft_strlen(s))
		if ((s[i] == '+' || s[i] == '-') && !ft_isdigit(s[i + 1]))
			return (0);
	return (1);
}

/*
**Used by function called "populate" in main.
**This function checks for duplicate values.
*/

static int	check_duplicates(char **s)
{
	int i;
	int j;
	int args;

	i = 0;
	args = 0;
	while (s[args])
		args++;
	while (i < args - 1)
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] == s[j] || ft_atol(s[i]) == ft_atol(s[j]))
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

/*
**Used in function called "populate" in main
**This function will be used as validation.
**The correct type of digit as well as checking for duplicates.
*/

void		error_check(t_all *all)
{
	int i;

	i = -1;
	while (all->args[++i])
	{
		if (!check_duplicates(all->args) || !check_digits(all->args[i]))
		{
			if (all->token == TOKEN_STR)
				ft_array_free(&all->args);
			free(all);
			ft_puterror_exit();
		}
	}
}