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

int	ft_ps_freestack(t_node **stack)
{
	t_node	*cur;
	t_node	*nxt;

	cur = *stack;
	nxt = NULL;
	while (cur)
	{
		nxt = cur->next;
		ft_ptr_freenull(&cur);
		cur = nxt;
	}
	*stack = NULL;
	return (0);
}

// OPERATIONS_UTILS
char	ft_ps_stacksel(t_node *stack, t_var *data)
{
	if (stack == data->sta)
		return ('a');
	if (stack == data->stb)
		return ('b');
	ft_ps_error(data, UNDEFERR);
	return(0);
}

int	ft_ps_ordersel(t_node *stack, t_var *data)
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

int	ft_ps_pushidx(t_node **stack, unsigned int idx, t_var *data)
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
int	ft_ps_findrange(t_node **stack, unsigned int chunksize, t_var *data)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	stacklen = ft_lstsize((t_list *)(*stack));
	t_node			*curt; //current topnode
	t_node			*curb; //current bottomnode
	unsigned int	maxidx;
	unsigned int	minidx;
	char			sel;

	sel = ft_ps_stacksel(*stack, data);
	if (sel == 'a')
	{
		minidx = data->chunkmin;
		maxidx = minidx + data->chunksize - 1;
	}
	else if (sel == 'b')
	{
		maxidx = ft_ps_getmaxidx(*stack, data->arrayln);
		minidx = maxidx;
	}
	i = 0;
	j = 0;
	curt = *stack;
	curb = ft_lst_getlast(*stack);
	if (chunksize > stacklen)
		chunksize = stacklen;
	
	if (*stack && (*stack)->idx >= minidx && (*stack)->idx <= maxidx && \
		(*stack)->idx < data->arrayln - 2)
	{
		ft_ps_pushrange (stack, minidx, data->chunksize, data);
		return (1);
	}
	while (curt && ++i <= stacklen / 2 + 1)
	{
		//check i from top
		curt = curt->next;
		if (curt && (curt)->idx >= minidx && (curt)->idx <= maxidx && (curt)->idx < data->arrayln - 2)
		{
			while (i > 0)
			{
				ft_ps_rot(stack, data);
				--i;
			}
			ft_ps_pushrange (stack, minidx, data->chunksize, data);
			return (1);
		}
		//check i from bottom
		else
		{
			j = 0;
			curb = *stack;
			while (j++ < stacklen - i /* && curb->next */)
				curb = curb->next;
			if (curb && (curb)->idx >= minidx && (curb)->idx <= maxidx && (curb)->idx < data->arrayln - 2)
			{
				j = i;
				while (j-- > 0)
                    ft_ps_rrot(stack, data);
				ft_ps_pushrange (stack, minidx, data->chunksize, data);
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

int	ft_ps_swap(t_node **stack, t_var *data)
{
	char	sel;
	
	sel = ft_ps_stacksel(*stack, data);
	if (ft_swap(stack))
		{
			if (ft_printf("s%c\n", sel) < 0)
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

int	ft_ps_rot(t_node **stack, t_var *data)
{
	char	sel;
	
	sel = ft_ps_stacksel(*stack, data);
	if (ft_rotate(stack))
		{
			if (ft_printf("r%c\n", sel) < 0)
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

int	ft_ps_rrot(t_node **stack, t_var *data)
{
	char	sel;
	
	sel = ft_ps_stacksel(*stack, data);
	if (ft_revrotate(stack))
		{
			if (ft_printf("rr%c\n", sel) < 0)
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

t_node	**ft_ps_pushsel(t_node *from, t_var *data)
{
	if (ft_ps_stacksel(from, data) == 'a')
		return (&data->stb);
	else if (ft_ps_stacksel(from, data) == 'b')
		return (&data->sta);
	else
		ft_ps_error(data, UNDEFERR);
	return (NULL);
}

int	ft_ps_push(t_node **from, t_var *data)
{
	char	sel;
	t_node	**to;

	to = ft_ps_pushsel(*from, data);
	sel = ft_ps_stacksel(*to, data);
	if (ft_push(from, to))
	{
		if (ft_printf("p%c\n", sel) < 0)
			ft_ps_error(data, WRITEERR);
		return (1);
	}
	return (0);
}

//chunksize is actual chunk size, not theoretical chunk size. Gets smaller by every push.
int	ft_ps_pushrange(t_node **from, UINT minidx, UINT chsize, t_var *data)
{
	UINT	maxidx;
	t_node	**to;
	char	sel;
	UINT	thenbr;

	sel = ft_ps_stacksel(*from, data);
	to = &data->stb;
	thenbr = (*from)->idx - 1;
	if (sel == 'b')
	{
		to = &data->sta;
		thenbr = (*from)->idx + 1;
	}
	//if the idx to push is the next bigger than topB, dont rotate, just push on top of B and it will be already sorted there.
	if (*to && (*to)->idx == thenbr)
	{
		ft_ps_push(from, data);
		return (1);
	}
	//else do the usual evaluation (biger half on top, smaller half on bottom)
	maxidx = minidx + chsize - 1;
	if (maxidx > data->arrayln)
		chsize -= (data->arrayln - 3) % chsize;
	if ((*from)->idx >= minidx && (*from)->idx < minidx + chsize / 2 - 1)
	{
		ft_ps_push(from, data);
		ft_ps_rot(to, data);
	}
	else if ((*from)->idx >= minidx + chsize / 2 - 1 && (*from)->idx <= maxidx)
		ft_ps_push(from, data);
	else
		ft_ps_error(data, UNDEFERR);
	return (1);
}
