/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_fns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:43:18 by mpalkov           #+#    #+#             */
/*   Updated: 2023/05/29 14:45:22 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_fillarr(int *array, UINT len, char **str, t_var *data)
{
	UINT	i;

	i = 0;
	while (i < len)
	{
		ft_ps_atoi(str[i + 1], array + i, data);
		++i;
	}
	return (1);
}

int	ft_swap_ints(int *a, int *b)
{
	int	tmp[1];

	tmp[0] = *a;
	*a = *b;
	*b = tmp[0];
	return (1);
}

int	ft_selection_sort(int *array, UINT len)
{
	UINT	i;
	UINT	j;
	UINT	idx;

	i = 0;
	while (i < len)
	{
		idx = i;
		j = i + 1;
		while (j < len)
		{
			if (array[j] < array[idx])
				idx = j;
			++j;
		}
		if (array[idx] < array[i])
			ft_swap_ints(array + i, array + idx);
		++i;
	}
	return (0);
}
