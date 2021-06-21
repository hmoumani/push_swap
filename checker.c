/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:34:16 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/21 21:47:40 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	init_args_bonus(t_info *info)
{
	info->stack_a = malloc(info->size_a * sizeof(int));
	if (!info->stack_a)
		return (ft_error("Error\n", NULL, NULL, NULL));
	info->stack_b = malloc(info->size_a * sizeof(int));
	if (!info->stack_b)
		return (ft_error("Error\n", NULL, info->stack_a, NULL));
	return (0);
}

int	check_argv_bonus(t_info *info)
{
	info->stack_a = NULL;
	info->stack_b = NULL;
	if (!is_string(info))
		return (ft_error("Error\n", NULL, NULL, NULL));
	if (init_args_bonus(info))
		return (ft_error("Error\n", info->stack_a, info->stack_b, NULL));
	if (to_int(info))
		return (ft_error("Error\n", info->stack_a, info->stack_b, NULL));
	if (check_dup(info) == 1)
		return (ft_error("Error\n", info->stack_a, info->stack_b, NULL));
	return (0);
}

int	is_a_sorted(int *t, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (t[i] < t[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	reverse_bonus(t_info *info)
{
	int	i;
	int	temp;
	int	end;

	end = info->size_a - 1;
	i = 0;
	while (i < info->size_a / 2)
	{
		temp = info->stack_a[i];
		info->stack_a[i] = info->stack_a[end];
		info->stack_a[end] = temp;
		end--;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		ret;
	char	*line;

	ret = 1;
	info.size_a = argc - 1;
	info.size_b = 0;
	info.args = argv + 1;
	if (argc == 1)
		return (0);
	if (check_argv_bonus(&info))
		return (1);
	reverse_bonus(&info);
	while (ret != 0)
	{
		ret = get_next_line(&line);
		if (handle_op(&info, line))
			return (1);
	}
	if (is_a_sorted(info.stack_a, info.size_a))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	ft_error("", info.stack_b, info.stack_a, NULL);
}
