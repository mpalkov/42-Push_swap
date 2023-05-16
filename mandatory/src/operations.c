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


// LIST_FUNCTIONS.c

t_node	*ft_ps_lstfind(t_node *lst, int key)
{
	while (lst)
	{
		if (lst->nbr == key)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_ps_lstiter(t_node *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(&(lst->nbr));
		lst = lst->next;
	}
	return ;
}

void	ft_printf_int(void *data)
{
	int	*num;

	num = (int *)data;
	printf("%d, ", *num);
	return ;
}

// OPERATIONS_UTILS
char	ft_ps_stacksel(t_node *stack, t_vars *data)
{
	if (stack == data->sta)
		return ('a');
	if (stack == data->stb)
		return ('b');
	ft_ps_error(data, UNDEFERR);
	return(0);
}

int	ft_ps_ordersel(t_node *stack, t_vars *data)
{
	char	st;

	st = ft_ps_stacksel(stack, data);
	if (st == 'a')
		return (DESCEND);
	if (st == 'b')
		return (ASCEND);
	ft_ps_error(data, UNDEFERR);
	return(0);
}

// OPERATIONS.c
int	ft_swap(t_node **stack)
{
	// t_node	tempnode;
	t_node	*tmp;

	if (!(*stack) || !(*stack)->next)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return (1);
}

int	ft_ps_swap(t_node **stack, t_vars *data)
{
	char	sel;
	
	sel = ft_ps_stacksel(*stack, data);
	if (ft_swap(stack))
		{
			if (printf("s%c\n", sel) < 0)
				ft_ps_error(data, WRITEERR);
			return(1);
		}
	return(0);
}

// int	ft_sa(t_node **stack)
// {
// 	if (ft_swap(stack) == 1)
// 	{
// 		printf("sa\n");
// 		return (1);
// 	}
// 	return (0);
// }

// CREATE ft_sb sa ss

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

int	ft_ps_rot(t_node **stack, t_vars *data)
{
	char	sel;
	
	sel = ft_ps_stacksel(*stack, data);
	if (ft_rotate(stack))
		{
			if (printf("r%c\n", sel) < 0)
				ft_ps_error(data, WRITEERR);
			return(1);
		}
	return(0);
}

// int	ft_ra(t_node **stack)
// {
// 	if (ft_rotate(stack) == 1)
// 	{
// 		printf("ra\n");
// 		return (1);
// 	}
// 	return (0);
// }

// CREATE ft_rb rr

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

int	ft_ps_rrot(t_node **stack, t_vars *data)
{
	char	sel;
	
	sel = ft_ps_stacksel(*stack, data);
	if (ft_revrotate(stack))
		{
			if (printf("rr%c\n", sel) < 0)
				ft_ps_error(data, WRITEERR);
			return(1);
		}
	return(0);
}

int	ft_push(t_node **from, t_node **to, t_vars *data)
{
//	t_node	*tmp1;
	t_node	*tmp2;
	
	if (!*from || !*to)
		return (0);
//	tmp1 = *to;
	tmp2 = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp2;
	
	return (1);
}

int	ft_ps_push(t_node **from, t_node **to, t_vars *data)
{
	char	sel;

	sel = ft_ps_stacksel(*to, data);
	if (ft_push(from, to))
		{
			if (printf("p%c\n", sel) < 0)
				ft_ps_error(data, WRITEERR);
			return (1);
		}
	return (0);
}
