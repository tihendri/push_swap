/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:16:58 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 23:49:02 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**These are all the allowed commands that will be used to manipulate
**the positions of the numbers.
**push is used to send the first number on a stack (either stack A or B)
**to the first position on the other stack.
*/

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

/*
**swap is used to switch the places of the first two numbers on a
**stack so that first becomes second and second now becomes first.
*/

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

/*
**rotate is used to send the first number on a stack to the
**back of the same stack, i.e. first becomes last and second
**becomes first - meaning all numbers (theoretically) shift
**one space up.
*/

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

/*
**reverse rotate does the exact opporsite of rotate, by
**sending the last number to the front and shift all
**other numbers one space down.
*/

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
