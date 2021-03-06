/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:38:51 by hmoumani          #+#    #+#             */
/*   Updated: 2021/09/20 18:14:29 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

int	ft_error(char *s, int *p, int *p2, void *p3)
{
	free(p);
	free(p2);
	free(p3);
	write(2, s, ft_strlen(s));
	return (1);
}

int	check_dup(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < info->size_a)
	{
		j = i + 1;
		while (j < info->size_a)
		{
			if (info->stack_a[i] == info->stack_a[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	sign_(int *sign, const char **str)
{
	*sign = 1;
	if ((*str)[0] == '-')
		*sign = -1;
	if ((*str)[0] == '-' || (*str)[0] == '+')
		*str = *str + 1;
}

int	ft_atoi(const char *str, int i, int *error)
{
	int					sign;
	unsigned long long	result;

	i = 0;
	while (str[0] == '\t' || str[0] == '\n' || str[0] == '\v'
		|| str[0] == '\f' || str[0] == ' ' || str[0] == '\r')
		str++;
	result = 0;
	sign_(&sign, &str);
	while (str[0] == '0')
		str++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i++] - '0');
		if ((result > 2147483648ULL && sign == -1)
			|| (result >= 2147483648ULL && sign == 1))
		{
			*error = 1;
			return (-1);
		}
	}
	return (result * sign);
}
