/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:07:20 by hmoumani          #+#    #+#             */
/*   Updated: 2021/08/04 16:33:15 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrr(t_info *info)
{
	rra(info);
	rrb(info);
	return (0);
}

void	last_operations(t_info *info, int first_top, int first_bottom)
{
	if (first_top - 1 <= first_bottom)
	{
		while (first_top > 0)
		{
			call_op("rb", rb, info);
			first_top--;
		}
		call_op("pa", pa, info);
	}
	else
	{
		while (first_bottom >= 0)
		{
			call_op("rrb", rrb, info);
			first_bottom--;
		}
		call_op("pa", pa, info);
	}
}

void	redirect_op(t_info *info, int f_top, int first, t_med *op_info)
{
	if (f_top - 1 <= first)
	{
		while (f_top > 0)
		{
			call_op("ra", ra, info);
			f_top--;
		}
		call_op("pb", pb, info);
		if (op_info->first_num > op_info->med / 2)
			call_op("rb", rb, info);
	}
	else
	{
		while (first >= 0)
		{
			call_op("rra", rra, info);
			first--;
		}
		call_op("pb", pb, info);
		if (op_info->sec_num > op_info->med / 2)
			call_op("rb", rb, info);
	}
}

int	get_max_pos(t_info *info)
{
	int	i;
	int	max;
	int	pos;

	i = 1;
	max = info->stack_a[0];
	pos = 0;
	while (i < info->size_a)
	{
		if (max < info->stack_a[i])
		{
			pos = i;
			max = info->stack_a[i];
		}
		i++;
	}
	return (pos);
}
