/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:01:19 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/21 20:12:16 by hmoumani         ###   ########.fr       */
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
