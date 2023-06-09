/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2_3_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:46:13 by mpalkov           #+#    #+#             */
/*   Updated: 2023/05/29 14:46:15 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ps_handle2(t_node **stack, t_var *data)
{
	int	issorted;
	int	order;

	issorted = 0;
	order = ft_ps_ordersel(*stack, data);
	while (!issorted)
	{
		issorted = ft_ps_sortedcheck(*stack, 2, order, data);
		if (issorted)
			return (1);
		else
			ft_ps_swap(stack, data);
	}	
	return (0);
}

int	ft_ps_sort3(t_node **stack, int order, t_var *data)
{
	UINT	key;

	key = ft_ps_getmaxidx(data->sta, ft_lstsize((t_list *)data->sta));
	if (order == DESCEND)
		key -= 2;
	if ((*stack)->idx == key)
		ft_ps_rot(stack, data);
	else if ((ft_lst_getlast(*stack))->idx == key)
		ft_ps_swap(stack, data);
	else if ((*stack)->next->idx == key)
		ft_ps_rrot(stack, data);
	return (0);
}

int	ft_ps_handle3(t_node **stack, t_var *data)
{
	int	issorted;
	int	order;

	issorted = 0;
	order = ft_ps_ordersel(*stack, data);
	while (!issorted)
	{
		issorted = ft_ps_sortedcheck(*stack, 3, order, data);
		if (issorted)
			return (1);
		else
			ft_ps_sort3(stack, order, data);
	}
	return (0);
}

int	ft_ps_sort5(t_var *data)
{
	int	a;
	int	b;
	int	minidx;

	a = 5;
	b = 0;
	while (a > 3)
	{
		minidx = ft_ps_getminidx(data->sta, ft_lstsize((t_list *)data->sta));
		ft_ps_pushidx(&data->sta, minidx, data);
		--a;
		++b;
	}
	ft_ps_handle3(&data->sta, data);
	while (b--)
		ft_ps_push(&data->stb, data);
	return (0);
}

int	ft_ps_handle5(t_node **stack, t_var *data)
{
	int	issorted;
	int	order;

	issorted = 0;
	order = ASCEND;
	while (!issorted)
	{
		issorted = ft_ps_sortedcheck(*stack, 5, order, data);
		if (issorted)
			return (1);
		else
			ft_ps_sort5(data);
	}
	return (0);
}
