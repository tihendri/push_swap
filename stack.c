/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:57:48 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 23:33:09 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**displays error and terminates the rest of the code.
*/

void	error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

/*
**Evaluates the numbers/digits (1, 2, 3, etc...) in the input.
**Includes negative numbers.
**If the number check fails, the function returns as incomplete (return (1))
*/

int		check_only_number(int ac, char **av)
{
	int i;
	int	j;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		if (!ft_isdigit(av[i][j]))
			return (0);
		while (ft_isdigit(av[i][j]))
			j++;
		if (av[i][j])
			return (0);
		i++;
	}
	return (1);
}

/*
**Evaluates input to check whether a value has been entered
**multiple times.
**Returns incomplete if there are doubles (return (1)).
*/

int		check_doubles(t_stack *a, int ac)
{
	t_lst	*temp;
	int		i;
	int		j;
	int		k;
	int		arr[ac + 1];

	temp = a->head;
	i = 0;
	while (temp)
	{
		arr[i++] = temp->n;
		temp = temp->next;
	}
	j = -1;
	while (j++ < i)
	{
		k = j;
		while (++k < i)
			if (arr[j] == arr[k])
				return (0);
	}
	return (1);
}

/*
**Checks if the input is big/small enough to be stored as an int,
**whether the t_lst exists and then adds the list.
**Create a swap variable (temp) in order to create space to allocate
**new values to list.
**Use ft_atol instead of ft_atoi, in case number is larger than MAXINT.
*/

void	lst_addtail_fast(char *str, t_lst **back)
{
	t_lst	*temp;
	long	num;

	num = ft_atol(str);
	if (num > 2147483647 || num < -2147483648)
		error();
	if (*back == NULL)
		return ;
	temp = malloc(sizeof(t_lst));
	temp->n = (int)num;
	temp->next = NULL;
	(*back)->next = temp;
	temp->prev = *back;
	*back = temp;
}

/*
**This is where the stack is created and values are allocated.
*/

void	build_stack(t_stack *a, t_stack *b, char **av, int ac)
{
	int		i;
	t_lst	*temp;

	i = 1;
	if (!check_only_number(ac, av) || !(a->head = malloc(sizeof(t_lst))))
		error();
	a->head->n = ft_atoi(av[i++]);
	a->head->prev = NULL;
	a->tail = a->head;
	while (i < ac)
		lst_addtail_fast(av[i++], &a->tail);
	if (!check_doubles(a, ac))
	{
		while (a->head)
		{
			temp = a->head;
			a->head = a->head->next;
			free(temp);
		}
		error();
	}
	b->head = NULL;
	b->tail = NULL;
}

void	build_stack_2(t_stack *a, t_stack *b, char **av, int ac)
{
	int		i;
	t_lst	*temp;

	i = 0;
	if (!check_only_number(ac, av) || !(a->head = malloc(sizeof(t_lst))))
		error();
	a->head->n = ft_atoi(av[i++]);
	a->head->prev = NULL;
	a->tail = a->head;
	while (i < ac)
		lst_addtail_fast(av[i++], &a->tail);
	if (!check_doubles(a, ac))
	{
		while (a->head)
		{
			temp = a->head;
			a->head = a->head->next;
			free(temp);
		}
		error();
	}
	b->head = NULL;
	b->tail = NULL;
}
