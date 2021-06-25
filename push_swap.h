/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:32 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/22 11:28:43 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include<string.h>

typedef struct s_info
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
	char	**args;
	int		*copy;
	int		size_copy;
	int		chunk_size;
}				t_info;

typedef struct s_curr_chunk
{
	int	start;
	int	end;
}				t_curr_chunk;

int		ft_error(char *s, int *p, int *p2, void *p3);
int		ft_strlen(char *s);
int		check_dup(t_info *info);
int		is_string(t_info *info);
int		to_int(t_info *info);
int		ft_atoi(const char *str, int i, int *error);
void	reverse(t_info *info);
int		sa(t_info *info);
int		sb(t_info *info);
int		ss(t_info *info);
int		pa(t_info *info);
int		pb(t_info *info);
int		ra(t_info *info);
int		rb(t_info *info);
int		rr(t_info *info);
int		rra(t_info *info);
int		rrb(t_info *info);
int		rrr(t_info *info);
void	call_op(char *name, int (*f)(t_info *), t_info *info);
int		is_sorted(int *t, int len);
int		init_args(t_info *info);
int		check_argv(t_info *info);
int		in_chunk(int val, t_info *info, t_curr_chunk *curr);
void	redirect_operation(t_info *info, int first_top, int first_bottom);
int		get_max_pos(t_info *info);
void	last_operations(t_info *info, int first_top, int first_bottom);

#endif