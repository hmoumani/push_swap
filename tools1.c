/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:55:02 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/18 15:07:05 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertionSort(t_info *info)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < info->size_copy)
	{
		key = info->copy[i];
		j = i - 1;
		while (j >= 0 && info->copy[j] > key)
		{
			info->copy[j + 1] = info->copy[j];
			j = j - 1;
		}
		info->copy[j + 1] = key;
		i++;
	}
}

void	reverse(t_info *info)
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
	i = 0;
	while (i < info->size_a)
	{
		info->copy[i] = info->stack_a[i];
		i++;
	}
	insertionSort(info);
}

int	to_int(t_info *info)
{
	int	i;
	int	is_error;

	i = 0;
	is_error = 0;
	while (i < info->size_a)
	{
		info->stack_a[i] = ft_atoi(info->args[i], 0, &is_error);
		if (is_error)
			return (1);
		i++;
	}
	return (0);
}

void	call_op(char *name, int (*f)(t_info *), t_info *info)
{
	ll++;
	if (f(info) != -1)
	{
		write(1, name, ft_strlen(name));
		write(1, "\n", 1);
	}
	name = NULL;
}