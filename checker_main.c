/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2019/08/20 11:53:04 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 23:06:08 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <limits.h>

/*
**void	print_stacks(t_all *all)
**{
**	fprintf(stderr, "\e[34mSize A = %d ", all->size_a);
**	fprintf(stderr, "\e[31mSTACK A = ");
**	for(int i = 0; i < all->size_a; i++)
**		fprintf(stderr, "%d ", all->int_stack_a[i]);
**	fprintf(stderr, "\e[0m\n");
**	fprintf(stderr, "\e[34mSize B = %d ", all->size_b);
**	fprintf(stderr, "\e[32mSTACK B = ");
**	for(int i = 0; i < all->size_b; i++)
**		fprintf(stderr, "%d ", all->int_stack_b[i]);
**	fprintf(stderr, "\e[0m\n");
**}
*/

void		put_ok_ko(t_all *all)
{
	if (check_ascii(all))
		ft_putstr_fd("\e[32mOK\n\e[0m", 2);
	else
		ft_putstr_fd("\e[31mko\n\e[0m", 2);
}

char		**join_arguments(char **av)
{
	int		i;
	char	**array;
	char	**split;

	i = -1;
	array = (char **)malloc(sizeof(char *));
	*array = NULL;
	while (av[++i] != NULL)
	{
		if (!ft_strcmp(av[i], "-v") || !ft_strcmp(av[i], "-c") ||
		!ft_strcmp(av[i], "-d"))
			continue ;
		split = ft_strsplit(av[i], ' ');
		array = ft_array_join(array, split);
=======
/*   Created: 2019/07/15 10:05:43 by tihendri          #+#    #+#             */
/*   Updated: 2019/08/23 10:48:41 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_exit(t_stack *a, t_stack *b, int ok)
{
	t_lst	*tmp;

	while (a->head)
	{
		tmp = a->head;
		a->head = a->head->next;
		free(tmp);
	}
	while (b->head)
	{
		tmp = b->head;
		b->head = b->head->next;
		free(tmp);
	}
	if (ok)
		ft_putstr("OK\n");
	else if (!ok)
		ft_putstr("KO\n");
	exit(1);
}

int		check_a(t_stack *a)
{
	t_lst	*tmp;

	tmp = a->head;
	while (tmp->next != NULL)
	{
		if (tmp->next->n < tmp->n)
			return (0);
		tmp = tmp->next;
>>>>>>> a099a990ac43296f367492dcbd82c0da50b25c86
	}
	return (array);
}

<<<<<<< HEAD
int			main(int ac, char **av)
=======
int		main(int ac, char **av)
>>>>>>> a099a990ac43296f367492dcbd82c0da50b25c86
{
	t_all	*initialize_struct();
	void	fill_stack(t_all *all);
	t_all	*all;

<<<<<<< HEAD
	(void)ac;
	all = initialize_struct();
	all->args = join_arguments(av + 1);
	error_check(all);
	all->size = ft_array_size(all->args);
	all->size_a = all->size;
	fill_stack(all);
//	print_stacks(all);
	check_duplicates(all);
	if (check_ascii(all))
		return (0);
	while (get_next_line(0, &all->line) > 0)
	{
		check_moves(all, all->line);
//		print_stacks(all);
		if (all->line)
			ft_strdel(&all->line);
	}
	put_ok_ko(all);
	free_all(all);
	return (0);
=======
	if (ac < 2)
		return (0);
	build_stack(&a, &b, av, ac);
	while (get_next_line(0, &l) > 0)
	{
		if (!ft_strcmp(l, "sa") || !ft_strcmp(l, "sb") || !ft_strcmp(l, "ss"))
			swapper(l, &a, &b);
		else if (!ft_strcmp(l, "pa"))
			push(&b.head, &a.head, &a.tail);
		else if (!ft_strcmp(l, "pb"))
			push(&a.head, &b.head, &b.tail);
		else if (!ft_strcmp(l, "ra") || !ft_strcmp(l, "rb") || !ft_strcmp(l, "rr"))
			rotater(l, &a, &b);
		else if (!ft_strcmp(l, "rra") || !ft_strcmp(l, "rrb") || !ft_strcmp(l, "rrr"))
			rev_rotater(l, &a, &b);
		else
			print_exit(&a, &b, 0);
		free(l);
	}
	if (!check_a(&a) || b.head)
		print_exit(&a, &b, 0);
	print_exit(&a, &b, 1);
>>>>>>> a099a990ac43296f367492dcbd82c0da50b25c86
}
