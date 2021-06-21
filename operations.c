/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:39:12 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/21 20:15:30 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_info *info)
{
	int	tmp;

	if (info->size_a < 2)
		return (-1);
	tmp = info->stack_a[info->size_a - 1];
	info->stack_a[info->size_a - 1] = info->stack_a[info->size_a - 2];
	info->stack_a[info->size_a - 2] = tmp;
	return (0);
}

int	sb(t_info *info)
{
	int	tmp;

	if (info->size_b < 2)
		return (-1);
	tmp = info->stack_b[info->size_b - 1];
	info->stack_b[info->size_b - 1] = info->stack_b[info->size_b - 2];
	info->stack_b[info->size_b - 2] = tmp;
	return (0);
}

int	ss(t_info *info)
{
	sa(info);
	sb(info);
	return (0);
}

int	pa(t_info *info)
{
	if (info->size_b < 1)
		return (-1);
	info->stack_a[info->size_a++] = info->stack_b[--info->size_b];
	return (0);
}

int	pb(t_info *info)
{
	if (info->size_a < 1)
		return (-1);
	info->stack_b[info->size_b++] = info->stack_a[--info->size_a];
	return (0);
}
