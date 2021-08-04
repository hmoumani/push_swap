#include "push_swap.h"

void	num_to_index(t_info *info)
{
	int	i;
	int	j;
	int	count;

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
		info->copy[i++] = count;
	}
	i = 0;
	while (i < info->size_a)
	{
		info->stack_a[i] = info->copy[i];
		++i;
	}
}
