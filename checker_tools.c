/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:25:07 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/22 10:47:00 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	handle_op1(t_info *info, char *line)
{
	if (!ft_strncmp(line, "rr", 3))
		rr(info);
	else if (!ft_strncmp(line, "rra", 4))
		rra(info);
	else if (!ft_strncmp(line, "rrb", 4))
		rrb(info);
	else if (!ft_strncmp(line, "rrr", 4))
		rrr(info);
	else if (ft_strncmp(line, "", 1))
	{
		free(line);
		return (ft_error("Error\n", info->stack_a, info->stack_b, NULL));
	}
	free(line);
	return (0);
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
	else
		return (handle_op1(info, line));
	free(line);
	return (0);
}
