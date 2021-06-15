/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:32 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/15 20:55:36 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_HPP
# define PUSH_SWAP_HPP
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_info
{
		int *stack_a;
		int *stack_b;
		int size_a;
		char **args;
}				t_info;

int		ft_error(char *s, int *p, int *p2);
int		ft_strlen(char *s);
int		check_dup(t_info *info);
int		is_string(t_info *info);
int		to_int(t_info *info);
int		ft_atoi(const char *str, int i, int *error);


#endif