/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:34:16 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/21 18:53:21 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		init_args(t_info *info)
{
	if (!(info->stack_a = malloc(info->size_a * sizeof(int))))
		return ft_error("Error\n", NULL, NULL, NULL);
	if (!(info->stack_b = malloc(info->size_a * sizeof(int))))
		return ft_error("Error\n", NULL, info->stack_b, NULL);
	return (0);
}

int		check_argv(t_info *info)
{
	info->stack_a = NULL;
	info->stack_b = NULL;
	if (!is_string(info))
		return ft_error("Error\n", NULL, NULL, NULL);
	if (init_args(info))
		return ft_error("Error\n", info->stack_a, info->stack_b, NULL);
	if (to_int(info))
		return ft_error("Error\n", info->stack_a, info->stack_b, NULL);
	if (check_dup(info) == 1)
		return ft_error("Error\n", info->stack_a, info->stack_b, NULL);
	return 0;
}

int	handle_op(t_info *info, char *line)
{
	if (!ft_strncmp(line, "sa", 3))
		sa(info);
	else if (!ft_strncmp(line, "sb", 3))
		sb(info);
	else if (!ft_strncmp(line, "ss", 3))
		ss(info);
	else if (!ft_strncmp(line, "pa", 3))
		pa(info);
	else if (!ft_strncmp(line, "pb", 3))
		pb(info);
	else if (!ft_strncmp(line, "ra", 3))
		ra(info);
	else if (!ft_strncmp(line, "rb", 3))
		rb(info);
	else if (!ft_strncmp(line, "rr", 3))
		rr(info);
	else if (!ft_strncmp(line, "rra", 4))
		rra(info);
	else if (!ft_strncmp(line, "rrb", 4))
		rrb(info);
	else if (!ft_strncmp(line, "rrr", 4))
		rrr(info);
	else if(ft_strncmp(line, "", 1))
	{
		return (ft_error("Error\n", info->stack_a, info->stack_b, NULL));
	}
	return (0);
}

int		is_a_sorted(int *t, int len)
{
	int i;

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

int main(int argc, char **argv)
{
	t_info info;
	int ret;
	char *line;

	ret = 1;
	info.size_a = argc - 1;
	info.size_b = 0;
	info.args = argv + 1;
	if (argc == 1)
		return (0);
	if (check_argv(&info))
		return (1);
	reverse_bonus(&info);
	while (ret != 0)
	{
		ret = get_next_line(0, &line);
		if (handle_op(&info, line))
			return (1);
	}
	if (is_a_sorted(info.stack_a, info.size_a))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
		
}