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
		return (ASCEND);
	if (st == 'b')
		return (DESCEND);
	ft_ps_error(data, UNDEFERR);
	return(0);
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

int	ft_ps_pushidx(t_node **stack, unsigned int idx, t_vars *data)
{
	while (*stack)
	{
		if ((*stack)->idx == idx)
		{
			ft_ps_push(stack, data);
			return (1);
		}
		else if ((*stack)->next && (*stack)->next->idx == idx)
		{
			ft_ps_rot(stack, data);
			ft_ps_push(stack, data);
			return (1);
		}
		else if ((ft_lst_getlast(*stack))->idx == idx)
			{
				ft_ps_rrot(stack, data);
				ft_ps_push(stack, data);
				return (1);
			}
		else if ((*stack)->next)
			ft_ps_rot(stack, data);
		else if (!(*stack)->next)
			ft_ps_error(data, UNDEFERR);
	}
	return (0);
}

// MAXIDX - max index of the actual chunk.
// THE MINIDX for actual chunk will be always the lowest of the whole stack A
int	ft_ps_pushidxBIG(t_node **stack, unsigned int chunksize, t_vars *data)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	stacklen = ft_lstsize((t_list *)(*stack));
	t_node			*curt; //current topnode
	t_node			*curb; //current bottomnode
	unsigned int	minidx;
	unsigned int	maxidx;

	i = 0;
	j = 0;
	curt = *stack;
	curb = ft_lst_getlast(*stack);
	minidx = ft_ps_getminidx(*stack, data->arrayln);
	maxidx = minidx + chunksize + 1;
	
	if (*stack && (*stack)->idx >= minidx && (*stack)->idx <= maxidx)
	{
		ft_ps_push(stack, data);
		return (1);
	}
	while (curt && ++i < stacklen)
	{
		//check i from top
		curt = curt->next;
		if (curt && (curt)->idx >= minidx && (curt)->idx <= maxidx)
		{
			while (i--)
				ft_ps_rot(stack, data);
			// write another push which decides if pb rb (smaller half of chunk) OR pb only (bigger half of chunk)
			ft_ps_push(stack, data);
			return (1);
		}
		//check i from bottom
		else
		{
			j = i - 1;
			curb = *stack;
			while (stacklen - j-- >= 0 && curb->next)
				curb = curb->next;
			if (curb && (curb)->idx >= minidx && (curb)->idx <= maxidx)
			{
				while (++j <= stacklen)
					ft_ps_rrot(stack, data);
				ft_ps_push(stack, data);
				return (1);
			}
		}
	}
	return (0);
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

int	ft_push(t_node **from, t_node **to)
{
	t_node	*tmp;
	
	if (!*from)
		return (0);
	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
	
	return (1);
}

t_node	**ft_ps_pushsel(t_node *from, char *to, t_vars *data)
{
	if (ft_ps_stacksel(from, data) == 'a')
	{
		*to = 'b';
		return (&data->stb);
	}
	else if (ft_ps_stacksel(from, data) == 'b')
	{
		*to = 'a';
		return (&data->stb);
	}
	else
		ft_ps_error(data, UNDEFERR);
	return (NULL);
}

int	ft_ps_push(t_node **from, t_vars *data)
{
	char	sel;
	t_node	**to;

	to = ft_ps_pushsel(*from, &sel, data);
	if (ft_push(from, to))
	{
		if (printf("p%c\n", sel) < 0)
			ft_ps_error(data, WRITEERR);
		return (1);
	}
	return (0);
}

int	ft_ps_pushrange(t_node **from, unsigned int minidx, unsigned int chunksize, t_vars *data)
{
	unsigned int	maxidx;

	maxidx = minidx + chunksize + 1;
	if ((*from)->idx >= minidx && (*from)->idx < minidx + chunksize / 2)
	{
		ft_ps_push(from, data);
		ft_ps_rot(&data->stb, data);
	}
	else if ((*from)->idx >= minidx + chunksize / 2 && (*from)->idx <= maxidx)
		ft_ps_push(from, data);
	else
		ft_ps_error(data, UNDEFERR);
	return (0);
}
