/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:11:30 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 22:35:57 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_all	*initialize_struct(void)
{
	t_all *all;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		exit(EXIT_FAILURE);
	all->int_stack_a = 0;
	all->int_stack_b = 0;
	all->args = NULL;
	all->size = 0;
	all->size_a = 0;
	all->size_b = 0;
	return (all);
}
