/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:38:51 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/15 21:20:02 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return i;
	while (s[i])
		i++;
	return (i);
}

int		ft_error(char *s, int *p, int *p2)
{
	free(p);
	free(p2);
	write(2, s, ft_strlen(s));
	return (1);
}

int		check_dup(t_info *info)
{
	for (int i = 0; i < info->size_a; i++) {
		for (int j = i + 1; j < info->size_a; j++) { 
			if (info->stack_a[i] == info->stack_a[j]) {
				return (1);
			}
		}
	}
	return (0);
}

int		is_string(t_info *info)
{
	int i;
	int j;
	int len;

	i = 0;
	while (i < info->size_a)
	{
		j = 0;
		if (info->args[i][0] == '-' || info->args[i][0] == '+')
			j++;
		len = ft_strlen(info->args[i]);
		while (j < len)
		{
			if (info->args[i][j] < '1' || info->args[i][j] > '9')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_atoi(const char *str, int i, int *error)
{
	int					sign;
	unsigned long long	result;

	i = 0;
	while (str[0] == '\t' || str[0] == '\n' || str[0] == '\v' ||
			str[0] == '\f' || str[0] == ' ' || str[0] == '\r')
		str++;
	result = 0;
	sign = (str[0] == '-' ? -1 : 1);
	str = (str[0] == '-' || str[0] == '+') ? str + 1 : str;
	while (str[0] == '0')
		str++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i++] - '0');
		if ((result > 2147483647ULL && sign == -1) ||
		(result >= 2147483648ULL && sign == 1))
		{
			*error = 1;
			return (sign == 1 ? -1 : 0);
		}
	}
	return (result * sign);
}

int		to_int(t_info *info)
{
	int i;
	int is_error;

	i = 0;
	is_error = 0;
	while (i < info->size_a)
	{
		info->stack_a[i] = ft_atoi(info->args[i], 0, &is_error);
		if (is_error)
			return 1;
		i++;
	}
	return 0;
}