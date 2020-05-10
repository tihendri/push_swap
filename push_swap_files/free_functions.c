/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:48:06 by tihendri          #+#    #+#             */
/*   Updated: 2019/12/19 23:32:31 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**t_list structure is in libft.h file, while t_lst is in push_swap.h file
*/

void	free_stacks(t_stack *a, t_stack *b)
{
	t_lst	*temp;

	while (a->head)
	{
		temp = a->head;
		a->head = a->head->next;
		free(temp);
	}
	free(a->sub_lst);
	free(b->sub_lst);
}

void        free_str(char **args, int ac_temp)
{
	int i;

    i = -1;
	while (++i < ac_temp)
		free(args[i]);
}

void	free_list(t_list *command)
{
	t_list	*temp_list;

	while (command)
	{
		temp_list = command;
		command = command->prev;
		free(temp_list);
	}
}