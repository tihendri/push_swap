/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:03:46 by tihendri          #+#    #+#             */
/*   Updated: 2019/08/15 14:04:41 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstaddtail(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = *alst;
	if (temp == NULL)
	{
		*alst = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
			temp->prev = temp;
		}
		temp->next = new;
		new->next = NULL;
	}
}
