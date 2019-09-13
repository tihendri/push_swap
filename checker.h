/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:53:36 by tihendri          #+#    #+#             */
/*   Updated: 2019/09/12 23:03:29 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_all
{
	int			*int_stack_a;
	int			*int_stack_b;
	char		**args;
	int			size;
	char		*line;
	int			size_a;
	int			size_b;
	int			*sorted;
	char		**stack;
	char		**stack_a;
	char		**tmp;
	int			k;
	int			m;
	int			a_counter;
	int			b_counter;
	int			i;
	int			j;
	int			b;
	int			count;
	int			a_stack_size;
	int			low;
	int			mid;
	int			high;
}					t_all;

int					check_ascii(t_all *all);

int					check_int(int *array, int c, int n);
void				check_duplicates(t_all *all);

int					check_digits(char *s);

void				other_moves(t_all *all, char *line);
void				check_moves(t_all *all, char *line);

void				error_check(t_all *all);

void				free_all(t_all *all);

void				ft_array_free(char ***array);

char				**ft_array_join(char **arr1, char **arr2);

int					ft_array_size(char **arr);

void				pa(t_all *all);
void				pb(t_all *all);

void				rra(t_all *all);
void				rrb(t_all *all);
void				rrr(t_all *all);

void				ra(t_all *all);
void				rb(t_all *all);
void				rr(t_all *all);

void				swap(int *a, int *b);

void				sa(t_all *all);
void				sb(t_all *all);
void				ss(t_all *all);

void				swap(int *a, int *b);

char				**join_arguments(char **av);
void				put_ok_ko(t_all *all);

void				fill_stack(t_all *all);
t_all				*initialize_struct(void);

void				print_stacks(t_all *all);
#endif
