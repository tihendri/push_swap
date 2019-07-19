/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:44:48 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/19 13:42:22 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

/*
**Global variables
*/

char				g_buf[4096];
int							g_i;

/*
**Node structure
*/

typedef struct		s_node
{
	struct s_node	*next;
	int				value;
}					t_node;

/*
**List structure
*/

typedef struct		s_lst
{
	size_t			value;
	size_t			coup;
	struct s_node	*head;
	struct s_node	*tail;
}					t_lst;

/*
**from visual display
*/

void				ft_error(void);
void				ft_bufset(void);
void				ft_printout(t_lst *stack_a, t_lst *stack_b);
void				ft_buf(char *str, t_lst *stack_a, t_lst *stack_b);

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
