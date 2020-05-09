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

static void	error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

/*
**Evaluates the numbers/digits (1, 2, 3, etc...) in the input.
**Includes negative numbers.
**If the number check fails, the function returns as incomplete (return (1))
*/

static int	check_only_number(int ac, char **av, t_stack *a)
{
	int i;
	int	j;

	if (ac == 2 || a->argc_temp == 1)
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
**frees stack a before exit to resolve memory
**vulnerability.
*/
static void free_will_stack_ints(t_stack *a)
{
	t_lst	*temp;

	while (a->head)
	{
		temp = a->head;
		a->head = a->head->next;
		free(temp);
	}
	error();
}

// static void free_will_stack_str(t_stack *a, char **args)
// {
// 	t_lst	*temp;
// 	int		i;

// 	i = 0;
// 	while (a->head)
// 	{
// 		temp = a->head;
// 		a->head = a->head->next;
// 		free(temp);
// 	}
// 	while (args[i])
// 		free(args[i++]);
// 	error();
// }

// static void free_will_av(char **av)
// {
// 	int		i;

// 	i = 0;
// 	while (av[i])
// 		free(av[i++]);
// 	error();
// }

/*
**Evaluates input to check whether a value has been entered
**multiple times.
**Returns incomplete if there are doubles (return (1)).
*/

// static void	check_doubles_str(t_stack *a, char **args, int ac)
// {
// 	t_lst	*temp;
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		arr[ac + 1];

// 	temp = a->head;
// 	if (temp->next == NULL)
// 		return ;
// 	i = 0;
// 	while (temp)
// 	{
// 		arr[i++] = temp->value;
// 		temp = temp->next;
// 	}
// 	j = -1;
// 	while (j++ < i)
// 	{
// 		k = j;
// 		while (++k < i)
// 			if (arr[j] == arr[k])
// 				free_will_stack_str(a, args);
// 	}
// }

static void	check_doubles_ints(t_stack *a, int ac)
{
	t_lst	*temp;
	int		i;
	int		j;
	int		k;
	int		arr[ac + 1];

	temp = a->head;
	if (temp->next == NULL)
		return ;
	i = 0;
	while (temp)
	{
		arr[i++] = temp->value;
		temp = temp->next;
	}
	j = -1;
	while (j++ < i)
	{
		k = j;
		while (++k < i)
			if (arr[j] == arr[k])
				free_will_stack_ints(a);
	}
}

/*
**Checks if the input is big/small enough to be stored as an int,
**whether the t_lst exists and then adds the list.
**Create a swap variable (temp) in order to create space to allocate
**new values to list.
**Use ft_atol instead of ft_atoi, in case number is larger than MAXINT.
*/

static void	lst_addtail_fast(char *str, t_lst **back, t_lst *holder)
{
	t_lst	*temp;
	int		num;

	num = ft_atoi(str);
	// if (num > 2147483647 || num < -2147483648)
	// 	return ;
	// if (ft_is_too_big(num))
	// 	return ;
	if (*back == NULL)
		return ;
	if (!(temp = malloc(sizeof(t_lst))))
		error();
	temp->value = num;
	temp->next = NULL;
	(*back)->next = temp;
	temp->prev = *back;
	*back = temp;
	temp = holder;
	free(temp);
}

/*
**This is where the stack is created and values are allocated.
**For multiple arguments.
*/

void		build_stack(t_stack *a, t_stack *b, char **av, int ac)
{
	int		i;
	// t_lst	*temp;
	t_lst	*holder;

	i = 1;
	holder = NULL;
	if (!check_only_number(ac, av, a) || !(a->head = malloc(sizeof(t_lst))))
		error();
	a->head->value = ft_atoi(av[i++]);
	a->head->prev = NULL;
	a->tail = a->head;
	while (i < ac)
	{
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648)
			free_will_stack_ints(a);
		lst_addtail_fast(av[i++], &a->tail, holder);
	}
	check_doubles_ints(a, ac);
	// if (!check_doubles(a, ac))
	// {
	// 	while (a->head)
	// 	{
	// 		temp = a->head;
	// 		a->head = a->head->next;
	// 		free(temp);
	// 	}
	// 	error();
	// }
	b->head = NULL;
	b->tail = NULL;
}

/*
**For string argument.
*/

void		build_stack_str(t_stack *a, t_stack *b, char **args, int ac)
{
	int		i;
	// t_lst	*temp;
	t_lst	*holder;

	i = 1;
	holder = NULL;
	if (!check_only_number(ac, args, a) || !(a->head = malloc(sizeof(t_lst))))
		error();
	a->head->value = ft_atoi(args[i++]);
	a->head->prev = NULL;
	a->tail = a->head;
	while (i < ac)
	{
		if (ft_atol(args[i]) > 2147483647 || ft_atol(args[i]) < -2147483648)
		{
			free(*args);
			free_will_stack_ints(a);
		}
		lst_addtail_fast(args[i++], &a->tail, holder);
	}
	check_doubles_ints(a, ac);
	// check_big_small_int(a, ac);
	// if (!check_doubles(a, ac))
	// {
	// 	while (a->head)
	// 	{
	// 		temp = a->head;
	// 		a->head = a->head->next;
	// 		free(temp);
	// 	}
	// 	error();
	// }
	b->head = NULL;
	b->tail = NULL;
}
