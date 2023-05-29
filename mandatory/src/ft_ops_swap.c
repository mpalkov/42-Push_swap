/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:46:02 by mpalkov           #+#    #+#             */
/*   Updated: 2023/05/29 14:46:05 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_node **stack)
{
	t_node	*tmp;

	if (!(*stack) || !(*stack)->next)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return (1);
}

int	ft_ps_swap(t_node **stack, t_var *data)
{
	char	sel;

	sel = ft_ps_stacksel(*stack, data);
	if (ft_swap(stack))
	{
		if (ft_printf("s%c\n", sel) < 0)
			ft_ps_exit(data, WRITEERR);
		return (1);
	}
	return (0);
}
