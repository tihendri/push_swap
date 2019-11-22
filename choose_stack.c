/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:08:16 by tihendri          #+#    #+#             */
/*   Updated: 2019/11/22 13:08:20 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     count_entries(char **args)
{
    int i;

    i = 0;
    while (args[i] != '\0')
        i++;
    return (i);
}

void    choose_stack(t_stack *a, t_stack *b, char **av, int ac)
{
    char    **args;

    if (ac == 2)
    {
        args = ft_strsplit(av[1], ' ');
        a->acnt = count_entries(args);
        build_stack_2(a, b, args, a->acnt);

    }
    else
    {
        a->acnt = ac;
        build_stack(a, b, av, ac);
    }
}
