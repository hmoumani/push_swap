/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:32 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/20 20:07:45 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_HPP
# define PUSH_SWAP_HPP
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include<string.h>
# define CHUNK_SIZE 40;

typedef struct	s_info
{
		int *stack_a;
		int *stack_b;
		int size_a;
		int size_b;
		char **args;
		int *copy;
		int size_copy;
		int	chunk_start;
		int	chunk_end;
}				t_info;

typedef struct s_curr_chunk
{
	int	start;
	int end;
}				t_curr_chunk;

int ll;

int		ft_error(char *s, int *p, int *p2, int *p3);
int		ft_strlen(char *s);
int		check_dup(t_info *info);
int		is_string(t_info *info);
int		to_int(t_info *info);
int		ft_atoi(const char *str, int i, int *error);
void	reverse(t_info *info);
int	sa(t_info *info);
int	sb(t_info *info);
int	ss(t_info *info);
int	pa(t_info *info);
int	pb(t_info *info);
int	ra(t_info *info);
int	rb(t_info *info);
int	rr(t_info *info);
int	rra(t_info *info);
int	rrb(t_info *info);
int	rrr(t_info *info);
void	call_op(char *name, int (*f)(t_info *), t_info *info);
int		is_sorted(int *t, int len);


#endif