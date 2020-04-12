/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:45:12 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 17:06:13 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**ft_array_join(char **arr1, char **arr2)
{
	int		i;
	int		j;
	int		array_size;
	char	**strarr;

	i = -1;
	array_size = ft_array_size(arr1) + ft_array_size(arr2);
	if (!(strarr = (char **)malloc(sizeof(char *) * array_size + 1)))
		return (NULL);
	while (arr1[++i])
		strarr[i] = ft_strdup(arr1[i]);
	ft_array_free(&arr1);
	j = 0;
	while (arr2[j] != NULL)
	{
		strarr[i + j] = ft_strdup(arr2[j]);
		j++;
	}
	ft_array_free(&arr2);
	strarr[j + i] = NULL;
	return (strarr);
}
