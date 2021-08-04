/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:06:25 by hmoumani          #+#    #+#             */
/*   Updated: 2021/08/04 16:33:11 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_info *info)
{
	int	temp;
	int	i;

	if (info->size_a < 1)
		return (-1);
	i = info->size_a - 2;
	temp = info->stack_a[info->size_a - 1];
	while (i >= 0)
	{
		info->stack_a[i + 1] = info->stack_a[i];
		i--;
	}
	info->stack_a[0] = temp;
	return (0);
}

int	rb(t_info *info)
{
	int	temp;
	int	i;

	if (info->size_b < 1)
		return (-1);
	i = info->size_b - 2;
	temp = info->stack_b[info->size_b - 1];
	while (i >= 0)
	{
		info->stack_b[i + 1] = info->stack_b[i];
		i--;
	}
	info->stack_b[0] = temp;
	return (0);
}

int	rr(t_info *info)
{
	ra(info);
	rb(info);
	return (0);
}

int	rra(t_info *info)
{
	int	temp;
	int	i;

	i = 0;
	temp = info->stack_a[0];
	while (i < info->size_a - 1)
	{
		info->stack_a[i] = info->stack_a[i + 1];
		i++;
	}
	info->stack_a[i] = temp;
	return (0);
}

int	rrb(t_info *info)
{
	int	temp;
	int	i;

	i = 0;
	temp = info->stack_b[0];
	while (i < info->size_b - 1)
	{
		info->stack_b[i] = info->stack_b[i + 1];
		i++;
	}
	info->stack_b[i] = temp;
	return (0);
}
