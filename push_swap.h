/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:44:48 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/19 10:09:30 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

char				header_buf[4096];
int					header_i;

typedef struct		s_node
{
	struct s_node	*next;
	int		val;
}					t_node;

typedef struct		s_lst
{
	size_t	val;
	size_t	coup;
	struct	s_node	*head;
	struct	s_node	*tail;
}					t_lst;

# define INSTRUCTIONS 11

/*
**from moves files, instructions
*/

void				pa(t_lst *stack_a, t_lst *stack_b);
void				pb(t_lst *stack_a, t_lst *stack_b);
void				ra(t_lst *stack_a, t_lst *stack_b);
void				rb(t_lst *stack_a, t_lst *stack_b);
void				rr(t_lst *stack_a, t_lst *stack_b);
void				rra(t_lst *stack_a, t_lst *stack_b);
void				rrb(t_lst *stack_a, t_lst *stack_b);
void				rrr(t_lst *stack_a, t_lst *stack_b);
void				sa(t_lst *stack_a, t_lst *stack_b);
void				sb(t_lst *stack_a, t_lst *stack_b);
void				ss(t_lst *stack_a, t_lst *stack_b);

#endif
