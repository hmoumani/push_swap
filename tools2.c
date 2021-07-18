/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:01:19 by hmoumani          #+#    #+#             */
/*   Updated: 2021/07/18 17:38:50 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if (str2[i] == '\0' && str1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

int	is_string(t_info *info)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (i < info->size_a)
	{
		if (info->args[i][0] == 0)
			return (0);
		j = 0;
		if ((info->args[i][0] == '-' || info->args[i][0] == '+') &&
		info->args[i][1] != 0)
			j++;
		len = ft_strlen(info->args[i]);
		while (j < len)
		{
			if (info->args[i][j] < '0' || info->args[i][j] > '9')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	init_args(t_info *info)
{
	info->stack_a = malloc(info->size_a * sizeof(int));
	if (!info->stack_a)
		return (ft_error("Error\n", NULL, NULL, NULL));
	info->stack_b = malloc(info->size_a * sizeof(int));
	if (!info->stack_b)
		return (ft_error("Error\n", NULL, info->stack_a, NULL));
	info->copy = malloc(info->size_a * sizeof(int));
	if (!info->copy)
		return (ft_error("Error\n", info->stack_a, info->stack_b, NULL));
	return (0);
}

void	num_to_index(t_info *info)
{
	int	i;
	int	j;
	int count;

	i = 0;
	while (i < info->size_a)
	{
		j = 0;
		count = 0;
		while (j < info->size_a)
		{
			if (info->stack_a[i] > info->stack_a[j])
				count++;
			++j;
		}
		info->copy[i] = count;
		++i;
	}
	i = 0;
	while (i < info->size_a)
	{
		info->stack_a[i] = info->copy[i];
		++i;
	}
}

int	check_argv(t_info *info)
{
	if (!is_string(info))
		return (ft_error("Error\n", NULL, NULL, NULL));
	if (init_args(info))
		return (1);
	if (to_int(info))
		return (ft_error("Error\n", info->stack_a, info->stack_b, info->copy));
	if (check_dup(info) == 1)
		return (ft_error("Error\n", info->stack_a, info->stack_b, info->copy));
	num_to_index(info);
	reverse(info);
	if (info->size_a <= 100)
		info->chunk_size = info->size_a / 3;
	else
		info->chunk_size = info->size_a / 6 + 1;
	return (0);
}

int	in_chunk(int val, t_info *info, t_curr_chunk	*curr)
{
	int	i;

	i = curr->start;
	while (i < curr->end)
	{
		if (info->copy[i] == val)
			return (1);
		i++;
	}
	return (-1);
}
