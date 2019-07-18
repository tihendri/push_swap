/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:16:58 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/15 16:14:29 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**We need a pop and push function to take an element (value) and put it in
**another stack.
**One will take the head element from the one stack (pop function)
**and the other will insert that element in the other stack.
**pops the head element off from the stack and assigns the next element (2nd)
**as the (new) head element.
**This is the taking part of the push and pop functions.
*/

static t_lst		*pop(t_lst **list)
{
	t_lst	*temp;

	temp = *list;
	if ((*list)->next = *list)
		*list = NULL;
	else
	{
		(*list)->prev->next = (*list)->next;
		(*list)->next->prev = (*list)->prev;
		*list = (*list)->next;
	}
	temp->prev = NULL;
	temp->next = NULL;
	return (temp);
}

/*
**This function will essentially push the value passed and assign it as
**the head element of the stack.
**This is the inserting part of the push and pop functions.
*/

static void			push(t_lst **list, t_lst *element)
{
	if (*list == NULL)
	{
		element->prev = element;
		element->next = element;
	}
	else
	{
		element->prev = (*list)->prev;
		element->next = (*list);
		(*list)->prev->next = element;
		(*list)->prev = element;
	}
	*list = element;
}

/*
**The push_pull_element function now allows us to pop and push at the same
**time, so that it can be one executable command.
*/

static void			push_pull_element(t_lst **from, t_lst **to)
{
	t_lst	*element;

	if ((element = pop(from)))
		push(to, element);
}

/*
**push a--take the first element at the top of b and put it at the top of a.
**Do nothing if b is empty.
*/

void				pa(t_lst **stack_a, t_lst **stack_b)
{
	ft_putendl("pa");
	if (*stack_b)
		push_pull_element(stack_b, stack_a);
}

/*
**push b--take the first element at the top of a and put it at the top of b.
**Do nothing if a is empty.
*/

void				pb(t_lst **stack_a, t_lst **stack_b)
{
	ft_putendl("pb");
	if (*stack_a)
		push_pull_element(stack_a, stack_b);
}
