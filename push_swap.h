/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:32 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/16 13:50:22 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_HPP
# define PUSH_SWAP_HPP
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include<string.h>
typedef struct	s_info
{
		int *stack_a;
		int *stack_b;
		int size_a;
		int size_b;
		char **args;
		int *copy;
		int size_copy;
}				t_info;

int		ft_error(char *s, int *p, int *p2, int *p3);
int		ft_strlen(char *s);
int		check_dup(t_info *info);
int		is_string(t_info *info);
int		to_int(t_info *info);
int		ft_atoi(const char *str, int i, int *error);
void	reverse(t_info *info);
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);

#endif