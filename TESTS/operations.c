/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:24:57 by mpalkov           #+#    #+#             */
/*   Updated: 2023/04/19 15:35:27 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_node **stack)
{
	t_node	*tmp;

	tmp = NULL;
	if (!(*stack))
		return (0);
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	*stack = tmp->next;

	return (1);
}

int	ft_sa(t_node *stack)
{
	if (ft_swap(&stack) == 1)
	{
		printf("sa\n");
		return (1);
	}
	return (0);
}
