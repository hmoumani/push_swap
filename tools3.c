/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:33:42 by hmoumani          #+#    #+#             */
/*   Updated: 2021/08/31 19:37:02 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	num_to_index(t_info *info)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < info->size_a)
	{
		j = 0;
		count = 0;
		while (j < info->size_a)
		{
			if (info->stack_a[i] > info->stack_a[j])
				count++;
			++j;
		}
		info->copy[i++] = count;
	}
	i = 0;
	while (i < info->size_a)
	{
		info->stack_a[i] = info->copy[i];
		++i;
	}
}

void	save_less(t_info *info, int *j, int i, int op)
{
	if (op && info->size_copy > 5)
	{
		while (*j >= 0 && info->stack_b[*j] > info->stack_a[0]
			&& info->stack_b[*j] < info->copy[i])
		{
			call_op("pa", pa, info);
			call_op("ra", ra, info);
			*j = info->size_b - 1;
		}
	}
	else if (info->size_copy > 5)
	{
		while (info->stack_b[0] > info->stack_a[0]
			&& info->stack_b[0] < info->copy[i])
		{
			call_op("rrb", rrb, info);
			call_op("pa", pa, info);
			call_op("ra", ra, info);
		}
	}
}

void	config_chunk(t_info *info)
{
	if (info->size_copy > 100 && info->chunk_size > 20)
		info->chunk_size = info->size_a / 6 + 1;
	if (info->size_a > 300 && info->size_a < 500)
		info->chunk_size = info->size_a / 6 + 1;
	if (info->size_a > 100 && info->size_a < 300)
		info->chunk_size = info->size_a / 4 + 1;
	if (info->size_a < 50)
		info->chunk_size = info->size_a / 3;
	else if (info->size_a > 50 && info->size_a < 100)
		info->chunk_size = info->size_a / 4;
	if (info->size_a < 25)
		info->chunk_size = info->size_a;
}
