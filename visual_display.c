/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:14:13 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/18 16:35:33 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void		ft_bufset(void)
{
	int		n;

	n = 0;
	while (n < 4096)
	{
		header_buf[n] = '\0';
		n++;
	}
	header_i = 0;
}

void		ft_display(t_list *stack_a, t_list *stack_b)
{
	write(1, header_buf, header_i - 1);
	if (header_i < 4092)
		ft_putchar('\n');
	ft_bufset();
}

void		ps_ft_buf(char *str, t_lst *stack_a, t_lst *stack_b)
{
	ft_strcat(header_buf, str);
	if (ft_strlen(str) == 4)
		header_i++;
	header_i = header_i + 3;
	if (header_i >= 4092)
		ft_display(stack_a, stack_b);
}
