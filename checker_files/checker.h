/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:53:36 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/19 23:32:58 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define MAXINT 2147483648
# define TOKEN_STR 0
# define TOKEN_INT 1

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_all
{
	char			**args;
	char			*line;
	unsigned int	*int_stack_a;
	unsigned int	*int_stack_b;
	unsigned int	size;
	unsigned int	size_a;
	unsigned int	size_b;
	unsigned int	token;
}					t_all;

/*
**check_sorted.c
*/

int					check_sorted(t_all *all);

/*
**initialize_struct.c
*/

t_all				*initialize_struct(void);

/*
**exec_moves.c
*/

void				exec_moves(t_all *all, char *line);

/*
**error_check.c
*/

void				error_check(t_all *all);

/*
**ft_array_func.c
*/

int					ft_array_size(char **arr);
void				ft_array_free(char ***array);

/*
**populate_stack.c
*/

void				populate_stack(int ac, char **av, t_all *all);

/*
**all_moves.c
*/

void				pa(t_all *all);
void				pb(t_all *all);
void				rra(t_all *all);
void				rrb(t_all *all);
void				rrr(t_all *all);
void				ra(t_all *all);
void				rb(t_all *all);
void				rr(t_all *all);
void				sa(t_all *all);
void				sb(t_all *all);
void				ss(t_all *all);

/*
**ft_put.c
*/

void				ft_puterror_exit(void);
void				put_ok_ko(t_all *all);

/*
**visualize.c
*/
void				print_stacks_bonus(t_all *all, char **av);

void				free_all(t_all *all);
#endif
