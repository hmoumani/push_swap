/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:35:13 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/21 20:25:41 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include<string.h>
# include "get_next_line/get_next_line.h"

typedef struct s_info
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
	char	**args;
}				t_info;

int		is_string(t_info *info);
int		ft_error(char *s, int *p, int *p2, void *p3);
int		check_dup(t_info *info);
int		is_string(t_info *info);
int		to_int(t_info *info);
int		ft_atoi(const char *str, int i, int *error);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	call_op(char *name, int (*f)(t_info *), t_info *info);
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
int		handle_op1(t_info *info, char *line);
int		handle_op(t_info *info, char *line);

#endif