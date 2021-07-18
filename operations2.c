/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:07:20 by hmoumani          #+#    #+#             */
/*   Updated: 2021/07/18 17:42:59 by hmoumani         ###   ########.fr       */
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

void	redirect_operation(t_info *info, int first_top, int first_bottom, int first_num, int sec_num, int med)
{
	if (first_top - 1 <= first_bottom)
	{
		while (first_top > 0)
		{
			call_op("ra", ra, info);
			first_top--;
		}
		call_op("pb", pb, info);
		if (first_num > med)
			call_op("rb", rb, info);
		(void)first_num;
		(void)sec_num;
		(void)med;
	}
	else
	{
		while (first_bottom >= 0)
		{
			call_op("rra", rra, info);
			first_bottom--;
		}
		call_op("pb", pb, info);
		if (sec_num > med)
			call_op("rb", rb, info);
	}
	// printf("first_top : %d \n", info->stack_a[first_top]);
	// printf("first_bottom : %d \n", info->stack_a[info->size_a - first_bottom]);
	// printf("chunk size = %d\n", info->chunk_size);
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
