/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:55:02 by hmoumani          #+#    #+#             */
/*   Updated: 2021/06/16 14:46:33 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insertionSort(t_info *info)
{
    int i;
	int key;
	int j;
	
	i = 1;
    while (i < info->size_copy) {
        key = info->copy[i];
        j = i - 1;
        while (j >= 0 && info->copy[j] > key) {
            info->copy[j + 1] = info->copy[j];
            j = j - 1;
        }
        info->copy[j + 1] = key;
		i++;
    }
}

void	reverse(t_info *info)
{
	int i;
	int temp;
	int end;

	end = info->size_a - 1;
	i = 0;
	while (i < info->size_a/2) 
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
	i = 0;
	while (i < info->size_a)
	{
		i++;
	}
}