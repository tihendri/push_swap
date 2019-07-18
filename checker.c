/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:05:43 by tihendri          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/07/18 13:10:09 by tihendri         ###   ########.fr       */
=======
/*   Updated: 2019/07/17 14:20:51 by tihendri         ###   ########.fr       */
>>>>>>> 22f450029c12b5fcccdf3c70341428eff936d06a
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**This function merely displays char string input.
*/

int			error_msg(char *msg)
{
	ft_putendl(msg);
	return (1);
}

/*
**This is the main function of checker.
**Checks for arguments and return error message with return (1) to indicate
**the incompletion of the main. There must be atleast one argument as input
**(2 for argc).
**If the argument is not a list of numbers, return error.
**if the passed argument is smaller than the minimum amount that an integer
**can hold (last), return an error.
**Initialize last to current number in operation, then move on to the next one
*/

int			main(int argc, char **argv)
{
	int n;
	int i;
	int last;

	if (argc < 2)
		return (error_msg("Error!"));
	i = 1;
	last = -2147483648;
	while (i < argc)
	{
		if (!ft_isnum(argv[i]))
<<<<<<< HEAD
			return (error_msg("Error!"));
		c = ft_atoi(argv[i]);
		if (c < last)
			return (error_msg("KO!"));
		last = c;
=======
			return (error_msg("Error! You've got to give me actual numbers please. Otherwise I'll be here all day..."));
		n = ft_atoi(argv[i]);
		if (n < last)
			return (error_msg("KO! It didn't work mate, better luck next time"));
		last = n;
>>>>>>> 22f450029c12b5fcccdf3c70341428eff936d06a
		i++;
	}
	ft_putendl("OK");
	return (0);
}
