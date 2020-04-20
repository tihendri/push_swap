/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:53:30 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/24 16:58:19 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**Used in function called "populate" in main
**Get the size of the 2-dimentional aspect of an array, in other words,
**get the number of strings in the string array.
*/

int		ft_array_size(char **arr)
{
	int len;

	if (!arr)
		return (0);
	len = 0;
	while (arr[len])
		len++;
	return (len);
}

/*
**Used by function called "error_check" in error_check.c file
**A rather "overkill" of freeing, where each individual value
**is freed. This might cause a multiple freeing error...
*/

void	ft_array_free(char ***array)
{
	int i;

	i = 0;
	while ((*array)[i] != NULL)
	{
		free((*array)[i]);
		i++;
	}
	free(*array);
}
