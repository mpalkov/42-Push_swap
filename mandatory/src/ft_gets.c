/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:45:42 by mpalkov           #+#    #+#             */
/*   Updated: 2023/05/29 14:45:45 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lst_getlast(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_node	*ft_lst_getprelast(t_node *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

unsigned int	ft_ps_getminidx(t_node *stack, unsigned int len)
{
	unsigned int	min;

	min = UINT_MAX;
	while (len > 0 && stack)
	{
		if (min > stack->idx)
			min = stack->idx;
		if (stack->next)
			stack = stack->next;
		--len;
	}
	return (min);
}

unsigned int	ft_ps_getmaxidx(t_node *stack, unsigned int len)
{
	unsigned int	max;

	max = 0;
	while (len > 0)
	{
		if (max < stack->idx)
			max = stack->idx;
		if (stack->next)
			stack = stack->next;
		--len;
	}
	return (max);
}
