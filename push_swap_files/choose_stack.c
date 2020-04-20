/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:08:16 by tihendri          #+#    #+#             */
/*   Updated: 2019/12/19 13:08:20 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  count_entries(char **args)
{
    int i;

    i = 0;
    while (args[i])
        i++;
    return (i);
}

static int  check_one(char **ss)
{
    int i;

    i = 0;
    while(ss[0][i])
    {
        if (ss[0][i] >= '0' && ss[0][i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}
void        choose_stack(t_stack *a, t_stack *b, char **av, int ac)
{
    char    **args;
    long    r;

    if (ac == 1)
        exit(0);
    else if (ac == 2)
    {
        args = ft_strsplit(av[1], ' ');
        a->argc_temp = count_entries(args);
        if (a->argc_temp == 1)
        {
            r = ft_atol(args[0]);
            if (r > 2147483647 || r < -2147483648 || !check_one(args))
            {
                ft_putstr("Error\n");
                exit(1);
            }
            exit(0);
        }
        build_stack_str(a, b, args, a->argc_temp);
    }
    else if (ac > 2)
    {
        a->argc_temp = ac;
        build_stack(a, b, av, ac);
    }
}
