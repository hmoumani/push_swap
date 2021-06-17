/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:42 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/17 21:55:52 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		init_args(t_info *info)
{
	if (!(info->stack_a = malloc(info->size_a * sizeof(int))))
		return ft_error("Error\n", NULL, NULL, NULL);
	if (!(info->stack_b = malloc(info->size_a * sizeof(int))))
		return ft_error("Error\n", NULL, info->stack_b, NULL);
	if (!(info->copy = malloc(info->size_a * sizeof(int))))
		return ft_error("Error\n", info->stack_a, info->stack_b, NULL);
	return (0);
}
int		check_argv(t_info *info)
{
	if (!is_string(info))
		return ft_error("Error\n", NULL, NULL, NULL);
	if (init_args(info))
		return ft_error("Error\n", info->stack_a, info->stack_b, info->copy);
	if (to_int(info))
		return ft_error("Error\n", info->stack_a, info->stack_b, info->copy);
	if (check_dup(info) == 1)
		return ft_error("Error\n", info->stack_a, info->stack_b, info->copy);
	reverse(info);
	return 0;
}

void	test_op(t_info *info)
{
	// char in[100];
	
	// while (1)
	// {
	// 	scanf("%s", in);
	// 	if (!strcmp(in, "sa"))
	// 		sa(info);
	// 	else if (!strcmp(in, "sb"))
	// 		sb(info);
	// 	else if (!strcmp(in, "ss"))
	// 		ss(info);
	// 	else if (!strcmp(in, "pa"))
	// 		pa(info);
	// 	else if (!strcmp(in, "pb"))
	// 		pb(info);
	// 	else if (!strcmp(in, "ra"))
	// 		ra(info);
	// 	else if (!strcmp(in, "rb"))
	// 		rb(info);
	// 	else if (!strcmp(in, "rr"))
	// 		rr(info);
	// 	else if (!strcmp(in, "rra"))
	// 		rra(info);
	// 	else if (!strcmp(in, "rrb"))
	// 		rrb(info);
	// 	else if (!strcmp(in, "rrr"))
	// 		rrr(info);
		printf("\nstack a\n");
		for (int i = 0; i < info->size_a; i++)
		{
			printf("%d *", info->stack_a[i]);
		}
		printf("\n***************\n");
		printf("stack b\n");
		for (int i = 0; i < info->size_b; i++)
		{
			printf("%d *", info->stack_b[i]);
		}
		printf("\n***************\n");
	// }
}

int		in_chunk(int val, t_info *info,t_curr_chunk	*curr)
{
	int i;

	i = curr->start;
	while (i < curr->end)
	{
		if (info->copy[i] == val)
			return (1);
		i++;
	}
	return (-1);
}

void	redirect_operation(t_info *info, int first_top, int first_bottom)
{
	if (first_top - 1 <= first_bottom)
	{
		while (first_top > 0)
		{
			// ra(info);
			call_op("ra", ra, info);
			first_top--;
		}
		// pb(info);
		call_op("pb", pb, info);
	}
	else
	{
		while (first_bottom >= 0)
		{
			// rra(info);
			call_op("rra", rra, info);
			first_bottom--;
		}
		// pb(info);
		call_op("pb", pb, info);

	}
}

void	last_operations(t_info *info, int first_top, int first_bottom)
{
	if (first_top - 1 <= first_bottom)
	{
		while (first_top > 0)
		{
			// rb(info);
			call_op("rb", rb, info);
			first_top--;
		}
		// pa(info);
		call_op("pa", pa, info);
	}
	else
	{
		while (first_bottom >= 0)
		{
			// rrb(info);
			call_op("rrb", rrb, info);
			first_bottom--;
		}
		// pa(info);
		call_op("pa", pa, info);
	}
	// test_op(info);
}

void	handle_chunk(t_info *info, t_curr_chunk	*curr)
{
	int first_top;
	int first_bottom;
	int i;
	int j;

	j = curr->end - curr->start;

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
		first_bottom = i;
		redirect_operation(info, first_top, first_bottom);
		// printf("%d * %d\n", first_top, first_bottom);
		// test_op(info);
		// printf("******************\n");
		j--;
	}
}

void	fill_b(t_info *info)
{
	t_curr_chunk	curr;

	curr.start = 0;
	curr.end = CHUNK_SIZE;
	if (curr.end > info->size_copy)
		curr.end = info->size_copy;
	while (curr.start <= info->size_copy)
	{
		handle_chunk(info, &curr);
		curr.start = curr.end + 1;
		curr.end = curr.end + CHUNK_SIZE;
		if (curr.end > info->size_copy)
			curr.end = info->size_copy;
	}
}

void	fill_a(t_info *info)
{
	int i = info->size_copy - 1;
	int j;
	int first_top;
	int first_bottom;

	while (i >= 0)
	{
		first_top = 0;
		first_bottom = 0;
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
			first_bottom++;
			j++;
		}
		last_operations(info, first_top, first_bottom);
		// printf("%d * %d\n", first_top, first_bottom);
		// test_op(info);
		// printf("******************\n");
		i--;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	t_info info;
	info.size_a = argc - 1;
	info.size_copy = argc - 1;
	info.size_b = 0;
	info.args = argv + 1;
	if (check_argv(&info) == 1)
		return (1);
	// test_op(&info);
	fill_b(&info);
	fill_a(&info);
}
