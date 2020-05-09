/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:38:25 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 22:52:52 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**Used in main function,
**extra function created to respect the norm of max 25 lines per function.
**This function checks if the moves parsed to checker are valid moves,
**in which case it allows the move to be executed.
**Otherwise it calls function "ft_puterror_exit".
*/

static void	more_moves(t_all *all, char *line)
{
	if (!ft_strcmp(line, "rr"))
		rr(all);
	else if (!ft_strcmp(line, "rra"))
		rra(all);
	else if (!ft_strcmp(line, "rrb"))
		rrb(all);
	else if (!ft_strcmp(line, "rrr"))
		rrr(all);
	else
	{
		free_all(all);
		ft_puterror_exit();
	}
}

void		exec_moves(t_all *all, char *line)
{
	if (!ft_strcmp(line, "sa"))
		sa(all);
	else if (!ft_strcmp(line, "sb"))
		sb(all);
	else if (!ft_strcmp(line, "ss"))
		ss(all);
	else if (!ft_strcmp(line, "pa"))
		pa(all);
	else if (!ft_strcmp(line, "pb"))
		pb(all);
	else if (!ft_strcmp(line, "ra"))
		ra(all);
	else if (!ft_strcmp(line, "rb"))
		rb(all);
	else
		more_moves(all, line);
}
