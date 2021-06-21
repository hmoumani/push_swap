/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:42 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/21 16:28:05 by hmoumani         ###   ########.fr       */
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
	info->chunk_size = 16;
	if (info->size_a > 150)
		info->chunk_size = info->size_a / 12;
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
			call_op("ra", ra, info);
			first_top--;
		}
		call_op("pb", pb, info);
	}
	else
	{
		while (first_bottom >= 0)
		{
			call_op("rra", rra, info);
			first_bottom--;
		}
		call_op("pb", pb, info);

	}
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

void	handle_chunk(t_info *info, t_curr_chunk	*curr)
{
	int first_top;
	int first_bottom;
	int i;
	int j;

	j = curr->end - curr->start - 1;


	while (j >= 0)
	{
		first_top = 0;
		i = info->size_a - 1;
		while (i >= 0)
		{
			if (in_chunk(info->stack_a[i], info, curr) == 1){
				break ;
			}
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
		handle_chunk(info, &curr);
		// printf("%d ***** %d\n", curr.start, curr.end);
		curr.start = curr.end;
		curr.end = curr.end + info->chunk_size;
		if (curr.end > info->size_copy - 3)
			curr.end = info->size_copy - 3;
	}
}

void	fill_a(t_info *info)
{
	int i = info->size_copy - 4;
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
		i--;
	}
}

int		get_max_pos(t_info *info)
{
	int i;
	int max;
	int pos;

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

void	handle_three(t_info *info)
{
	// printf("%d\n", get_max_pos(info));
	// for (int i = 0; i < info->size_a; i++)
	// {
	// 	printf("%d *", info->stack_a[i]);
	// }
	// printf("\n");
	int pos = get_max_pos(info);
	if (pos == 0 )
	{
		if (info->stack_a[1] < info->stack_a[2])
			call_op("sa", sa, info);
	}
	else if (pos == 1)
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
	// for (int i = 0; i < info->size_a; i++)
	// {
	// 	printf("%d *", info->stack_a[i]);
	// }
	// printf("\n");
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	ll= 0;
	t_info info;
	info.size_a = argc - 1;
	info.size_copy = argc - 1;
	info.size_b = 0;
	info.args = argv + 1;
	if (check_argv(&info) == 1)
		return (1);
	if (is_sorted(info.stack_a, info.size_a))
		return (0);
	// for (int i = 0; i < info.size_a; i++)
	// {
	// 	fprintf(stderr, "%s *", info.args[i]);
	// }
	// fprintf(stderr, "\n");
	fill_b(&info);
	// for (int i = 0; i < info.size_a; i++)
	// {
	// 	fprintf(stderr ,"%d *", info.stack_a[i]);
	// }
	// fprintf(stderr, "*********\n");
	handle_three(&info);
	// fprintf(stderr, "*********\n");
	// for (int i = 0; i < info.size_a; i++)
	// {
	// 	fprintf(stderr ,"%d *", info.stack_a[i]);
	// }
	// fprintf(stderr, "\n");
	fill_a(&info);
}
