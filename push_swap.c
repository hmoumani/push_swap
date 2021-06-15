/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:23:42 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/15 21:03:24 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		init_args(t_info *info)
{
	if (!(info->stack_a = malloc(info->size_a * sizeof(int))))
		return ft_error("Error\n", NULL, NULL);
	if (!(info->stack_b = malloc(info->size_a * sizeof(int))))
		return ft_error("Error\n", NULL, NULL);
	return (0);
}
int		check_argv(t_info *info)
{
	if (!is_string(info))
		return ft_error("Error\n", NULL, NULL);
	if (init_args(info))
		return ft_error("Error\n", info->stack_a, info->stack_b);
	if (to_int(info))
		return ft_error("Error\n", info->stack_a, info->stack_b);
	if (check_dup(info) == 1)
		return ft_error("Error\n", info->stack_a, info->stack_b);
	return 0;
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return 0;
	t_info info;
	info.size_a = argc - 1;
	info.args = argv + 1;
	if (check_argv(&info) == 1)
		return (1);
	if (init_args(&info) == 1)
		return (1);
		
}