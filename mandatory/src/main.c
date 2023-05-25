/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:51:49 by mpalkov           #+#    #+#             */
/*   Updated: 2023/04/19 17:19:50 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ps_indexnodes(t_var *data)
{
	unsigned int	i;
	int		*arr;
	t_node	*tmp;

	i = 1;
	arr = data->sortedarray;
	while(i <= data->arrayln)
	{
		tmp = NULL;
		tmp = ft_ps_lstfind(data->sta, arr[i - 1]);
		if (tmp)
			tmp->idx = i;
		++i;
	}
	return (0);
}

int	ft_ps_sort_many(t_var *data)
{
	int	a;
	int	b;

	if (data->arrayln <= 250)
		data->chunksize = SIZEFOR100;
	else
		data->chunksize = SIZEFOR500;
	data->chunkmin = ft_ps_getminidx(data->sta, data->arrayln);
	a = ft_lstsize((t_list *)data->sta);
	b = 0;
	while (a > 3)
	{
		if (b == data->chunksize)
		{
			b = 0;
			data->chunkmin += data->chunksize;
			data->chunkmax += data->chunksize;
		}
		ft_ps_findrange(&data->sta, data->chunksize - b, data);
		--a;
		++b;
	}
	ft_ps_handle3(&data->sta, data);
	b = ft_lstsize((t_list *)data->stb);
	while (b--)
		ft_ps_findrange(&data->stb, 1, data);
	return (0);
}

int	ft_ps_handle_many(t_node **stack, t_var *data)
{
	int	issorted;
	int	order;

	issorted = 0;
	order = ASCEND;
	while (!issorted)
	{
		issorted = ft_ps_sortedcheck(*stack, 0, order, data);
		if (issorted)
			return (1);
		else
			ft_ps_sort_many(data);
	}
	return (0);
}

int	ft_ps_sorting(t_var *data)
{
	unsigned int	len;

	len = data->arrayln;
	if (len == 2)
		ft_ps_handle2(&data->sta, data);
	else if (len == 3)
		ft_ps_handle3(&data->sta, data);
	else if (len <= 5)
		ft_ps_handle5(&data->sta, data);
	else
		ft_ps_handle_many(&data->sta, data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	data;

	if (argc == 1)
		return (0);
	ft_ps_initialize(argc, argv, &data);
	ft_ps_sorting(&data);

	//free everything
	ft_ps_exit(&data, OK);
	return (0);
}