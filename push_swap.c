/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:42 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/22 10:41:15 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_chunk(t_info *info, t_curr_chunk	*curr, int j)
{
	int	first_top;
	int	i;

	while (j >= 0)
	{
		first_top = 0;
		i = info->size_a - 1;
		while (i >= 0)
		{
			if (in_chunk(info->stack_a[i], info, curr) == 1)
				break ;
			first_top++;
			i--;
		}
		i = 0;
		while (i < info->size_a)
		{
			if (in_chunk(info->stack_a[i], info, curr) == 1)
				break ;
			i++;
		}
		redirect_operation(info, first_top, i);
		j--;
	}
}

void	fill_b(t_info *info)
{
	t_curr_chunk	curr;

	curr.start = 0;
	curr.end = info->chunk_size;
	if (curr.end > info->size_copy - 3)
		curr.end = info->size_copy - 3;
	while (curr.start <= info->size_copy - 4)
	{
		handle_chunk(info, &curr, curr.end - curr.start - 1);
		curr.start = curr.end;
		curr.end = curr.end + info->chunk_size;
		if (curr.end > info->size_copy - 3)
			curr.end = info->size_copy - 3;
	}
}

void	fill_a(t_info *info, int i)
{
	int	j;
	int	first_top;

	while (i >= 0)
	{
		first_top = 0;
		j = info->size_b - 1;
		while (j >= 0)
		{
			if (info->copy[i] == info->stack_b[j])
				break ;
			first_top++;
			j--;
		}
		j = 0;
		while (j < info->size_b)
		{
			if (info->copy[i] == info->stack_b[j])
				break ;
			j++;
		}
		last_operations(info, first_top, j);
		i--;
	}
}

void	handle_three(t_info *info)
{
	if (get_max_pos(info) == 0)
	{
		if (info->stack_a[1] < info->stack_a[2])
			call_op("sa", sa, info);
	}
	else if (get_max_pos(info) == 1)
	{
		if (info->stack_a[0] < info->stack_a[2])
			call_op("rra", rra, info);
		else
		{
			call_op("sa", sa, info);
			call_op("ra", ra, info);
		}
	}
	else
	{
		if (info->stack_a[0] < info->stack_a[1])
		{
			call_op("sa", sa, info);
			call_op("rra", rra, info);
		}
		else
			call_op("ra", ra, info);
	}
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 1)
		return (0);
	info.size_a = argc - 1;
	info.size_copy = argc - 1;
	info.size_b = 0;
	info.args = argv + 1;
	if (check_argv(&info) == 1)
		return (1);
	if (is_sorted(info.stack_a, info.size_a))
	{
		ft_error("", info.stack_a, info.stack_b, info.copy);
		return (0);
	}
	fill_b(&info);
	handle_three(&info);
	fill_a(&info, info.size_copy - 4);
	ft_error("", info.stack_a, info.stack_b, info.copy);
	return (0);
}
