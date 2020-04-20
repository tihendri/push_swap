/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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
void	free_all(t_stack *a, t_list *command)
{
	t_lst	*temp;
	t_list	*temp_a;

	while (a->head)
	{
		temp = a->head;
		a->head = a->head->next;
		free(temp);
	}
	while (command)
	{
		temp_a = command;
		free(command->content);
		command = command->next;
		free(temp_a);
	}
	free(a->p);
}

int		main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_list	*command;

	choose_stack(&a, &b, av, ac);
	if (!(a.p = malloc(sizeof(t_lst*) * a.argc_temp)) ||
	!(b.p = malloc(sizeof(t_lst*) * a.argc_temp)))
		exit(1);
	a.argc = a.argc_temp;
	b.argc = a.argc_temp;
	a.start = 0;
	b.start = 0;
	a.p[a.start] = NULL;
	b.p[a.start] = NULL;
	command = solver(&a, &b);
	while (command != NULL)
	{
		ft_putstr((char *)command->content);
		command = command->next;
	}
	free(b.p);
	free_all(&a, command);
	// while (1);						//For memory leaks: run push_swap with this loop active, then "leaks push_swap"
	return (0);
}
