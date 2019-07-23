/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_for_moves.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:16:58 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/23 15:05:09 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_lst *a, t_lst *b, char *line)
{
	t_lst *temp;

	temp = a;
	ft_putendl(line);
	while (temp != NULL)
	{
		ft_putnbr(temp->n);
		temp = temp->next;
	}
	temp = b;
	ft_putstr("\nb : ");
	while (temp != NULL)
	{
		ft_putnbr(temp->n);
		temp = temp->next;
	}
	ft_putchar('\n');
}

void	push(t_lst **from, t_lst **to, t_lst **to_tail)
{
	t_lst *temp;

	if (*from == NULL)
		return ;
	temp = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	if (*to)
		(*to)->prev = temp;
	else
		*to_tail = temp;
	temp->next = *to;
	*to = temp;
	(*to)->prev = NULL;
}

void	swap(t_lst **head)
{
	t_lst *temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	temp->prev = *head;
	(*head)->next = temp;
	(*head)->prev = NULL;
}

void	rotate(t_lst **head, t_lst **tail)
{
	if (*head == NULL || *tail == NULL || (*head)->next == NULL)
		return ;
	(*tail)->next = *head;
	(*head)->prev = *tail;
	*head = (*head)->next;
	(*head)->prev = NULL;
	*tail = (*tail)->next;
	(*tail)->next = NULL;
}

void	rev_rotate(t_lst **head, t_lst **tail)
{
	if (*head == NULL || *tail == NULL || (*tail)->prev == NULL)
		return ;
	(*head)->prev = *tail;
	(*tail)->next = *head;
	*head = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	(*head)->prev = NULL;
}
