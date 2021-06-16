/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:42 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/16 14:46:12 by hmoumani         ###   ########.fr       */
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
	char in[100];
	
	while (1)
	{
		scanf("%s", in);
		if (!strcmp(in, "sa"))
			sa(info);
		else if (!strcmp(in, "sb"))
			sb(info);
		else if (!strcmp(in, "ss"))
			ss(info);
		else if (!strcmp(in, "pa"))
			pa(info);
		else if (!strcmp(in, "pb"))
			pb(info);
		else if (!strcmp(in, "ra"))
			ra(info);
		else if (!strcmp(in, "rb"))
			rb(info);
		else if (!strcmp(in, "rr"))
			rr(info);
		else if (!strcmp(in, "rra"))
			rra(info);
		else if (!strcmp(in, "rrb"))
			rrb(info);
		else if (!strcmp(in, "rrr"))
			rrr(info);
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
}