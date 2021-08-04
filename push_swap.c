/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:42 by hmoumani          #+#    #+#             */
/*   Updated: 2021/07/18 19:48:11 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_chunk(t_info *info, t_curr_chunk *curr, int j)
{
	int			first_top;
	int			i;
	int			temp;
	t_med		op_info;

	while (j >= 0)
	{
		first_top = 0;
		i = info->size_a - 1;
		while (i >= 0)
		{
			if (in_chunk(info->stack_a[i--], info, curr) == 1)
				break ;
			first_top++;
		}
		temp = info->stack_a[i + 1];
		i = 0;
		while (i < info->size_a)
			if (in_chunk(info->stack_a[i++], info, curr) == 1)
				break ;
		op_info = (t_med){temp, info->stack_a[i - 1], curr->start + curr->end};
		redirect_op(info, first_top, i - 1, &op_info);
		j--;
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

void	fill_b(t_info *info)
{
	t_curr_chunk	curr;

	curr.start = 0;
	curr.end = info->chunk_size;
	if (curr.end > info->size_copy - 3)
		curr.end = info->size_copy - 3;
	while (curr.start <= info->size_copy - 4)
	{
		config_chunk(info);
		handle_chunk(info, &curr, curr.end - curr.start - 1);
		curr.start = curr.end;
		curr.end = curr.end + info->chunk_size;
		if (curr.end > info->size_copy - 3)
			curr.end = info->size_copy - 3;
	}
}

void	save_less(t_info *info, int *j, int i,int op)
{
	if (op)
	{
		while (info->stack_b[*j] > info->stack_a[0] && info->stack_b[*j] < info->copy[i])
		{
			call_op("pa", pa, info);
			call_op("ra", ra, info);
			*j = info->size_b - 1;
		}
	}
	else
	{
		while (info->stack_b[0] > info->stack_a[0] && info->stack_b[0] < info->copy[i])
		{
			call_op("rrb", rrb, info);
			call_op("pa", pa, info);
			call_op("ra", ra, info);
		}
	}
}

void	fill_a(t_info *info, int i)
{
	int	j;
	int	first_top;

	info->stack_a[0] = -42;
	while (i >= 0)
	{
		while (info->copy[i] == info->stack_a[0])
		{
			call_op("rra", rra, info);
			--i;
		}
		first_top = 0;
		j = info->size_b - 1;
		// while (info->stack_b[j] > info->stack_a[0] && info->stack_b[j] < info->copy[i])
		// {
		// 	call_op("pa", pa, info);
		// 	call_op("ra", ra, info);
		// 	j = info->size_b - 1;
		// }
		save_less(info, &j, i, 1);
		while (j >= 0)
		{
			if (info->copy[i] == info->stack_b[j--])
				break ;
			first_top++;
		}
		// while (info->stack_b[0] > info->stack_a[0] && info->stack_b[0] < info->copy[i])
		// {
		// 	call_op("rrb", rrb, info);
		// 	call_op("pa", pa, info);
		// 	call_op("ra", ra, info);
		// }
		save_less(info, &j, i, 0);
		j = 0;
		while (j < info->size_b)
			if (info->copy[i] == info->stack_b[j++])
				break ;
		last_operations(info, first_top, j - 1);
		i--;
	}
}

void handle_three(t_info *info)
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

int main(int argc, char **argv)
{
	t_info info;

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
	if (argc == 3)
	{
		call_op("sa", sa, &info);
		return (0);
	}
	fill_b(&info);
	// printf("%d\n", info.size_a);
	handle_three(&info);
	fill_a(&info, info.size_copy - 4);
	// for (int i = 0; i < info.size_a; ++i){
	// 	printf("%d*", info.stack_a[i]);
	// }
	ft_error("", info.stack_a, info.stack_b, info.copy);
	return (0);
}
