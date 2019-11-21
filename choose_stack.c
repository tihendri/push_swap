#include "push_swap.h"

int     count_entries(char **args)
{
    int i;

    i = 0;
    while (args[i] != '\0')
    {
        i++;
    }
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