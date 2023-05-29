/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_r_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:45:59 by mpalkov           #+#    #+#             */
/*   Updated: 2023/05/29 14:46:01 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_node **stack)
{
	t_node	tempnode;
	t_node	*tmp;
	t_node	*last;

	if (!(*stack) || !(*stack)->next)
		return (0);
	tmp = &tempnode;
	last = ft_lst_getlast(*stack);
	tmp = *stack;
	*stack = (*stack)->next;
	last->next = tmp;
	tmp->next = NULL;
	return (1);
}

int	ft_ps_rot(t_node **stack, t_var *data)
{
	char	sel;

	sel = ft_ps_stacksel(*stack, data);
	if (ft_rotate(stack))
	{
		if (ft_printf("r%c\n", sel) < 0)
			ft_ps_exit(data, WRITEERR);
		return (1);
	}
	return (0);
}

int	ft_revrotate(t_node **stack)
{
	t_node	*pre_last;

	pre_last = ft_lst_getprelast(*stack);
	if (!pre_last)
		return (0);
	pre_last->next->next = *stack;
	*stack = pre_last->next;
	pre_last->next = NULL;
	return (1);
}

int	ft_ps_rrot(t_node **stack, t_var *data)
{
	char	sel;

	sel = ft_ps_stacksel(*stack, data);
	if (ft_revrotate(stack))
	{
		if (ft_printf("rr%c\n", sel) < 0)
			ft_ps_exit(data, WRITEERR);
		return (1);
	}
	return (0);
}
