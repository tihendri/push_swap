/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:56:26 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/13 06:43:10 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_all(t_all *all)
{
	if (all->args)
		ft_array_free(&all->args);
	if (all->int_stack_a)
		free(all->int_stack_a);
	if (all->int_stack_b)
		free(all->int_stack_b);
	free(all);
}
