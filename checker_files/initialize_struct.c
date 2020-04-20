/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:11:30 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/24 22:35:57 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**Called in main function.
**This functions initializes all the values in the structure created in the
**header file (*.h)
*/

t_all	*initialize_struct(void)
{
	t_all *all;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		exit(EXIT_FAILURE);
	all->args = NULL;
	all->line = NULL;
	all->int_stack_a = NULL;
	all->int_stack_b = NULL;
	all->size = 0;
	all->size_a = 0;
	all->size_b = 0;
	return (all);
}
