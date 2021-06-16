/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:39:12 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/16 14:06:43 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	int	tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->stack_a[info->size_a - 1];
	info->stack_a[info->size_a - 1] = info->stack_a[info->size_a - 2];
	info->stack_a[info->size_a - 2] = tmp;
}

void	sb(t_info *info)
{
	int	tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->stack_b[info->size_b - 1];
	info->stack_b[info->size_b - 1] = info->stack_b[info->size_b - 2];
	info->stack_b[info->size_b - 2] = tmp;
}

void	ss(t_info *info)
{
	sa(info);
	sb(info);
}

void	pa(t_info *info)
{
	if (info->size_b < 1)
		return ;
	info->stack_a[info->size_a++] = info->stack_b[(info->size_b--) - 1];
}

void	pb(t_info *info)
{
	if (info->size_a < 1)
		return ;
	info->stack_b[info->size_b++] = info->stack_a[(info->size_a--) - 1];
}
