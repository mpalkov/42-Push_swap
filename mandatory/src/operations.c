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
			ft_ps_exit(data, UNDEFERR);
	}
	return (0);
}

// void	ft_findrange_init(char *sel, UINT *min, UINT *max, t_var *data)
// {
// 	if (*sel == 'a')
// 	{
// 		*min = data->chunkmin;
// 		*max = min + data->chunksize - 1;
// 	}
// 	else if (*sel == 'b')
// 	{
// 		*max = ft_ps_getmaxidx(*stack, data->arrayln);
// 		*min = max;
// 	}
// 	return ;
// }



// MINIDX & MAXIDX se pueden sustituir por directamente data->chunkmin data->chunkmax
// DO 2 functions - ifA and ifB
// then within, another 2 with ft_searchfromtop ft_searchfrombottom

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
			while (j++ < stacklen - i)
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

void	ft_checkfrombottom()

void	ft_ps_pushrot(t_node **from, t_node **to, t_var *data)
{
		ft_ps_push(from, data);
		ft_ps_rot(to, data);
		return ;
}

// helper function for pushrange
void	ft_pr_init(char *sel, t_node *from, UINT *nbr, t_var *data)
{
	*nbr = from->idx - 1;
	*sel = ft_ps_stacksel(from, data);
	if (*sel == 'b')
		*nbr = from->idx + 1;
}
// if the idx to push is the next bigger than topB, dont rotate,
//		just push on top of B and it will be already sorted there.
//else do the usual evaluation (biger half on top, smaller half on bottom)
int	ft_ps_pushrange(t_node **from, UINT minidx, UINT chsize, t_var *data)
{
	UINT	maxidx;
	t_node	**to;
	char	sel;
	UINT	thenbr;

	ft_pr_init(&sel, *from, &thenbr, data);
	to = &data->stb;
	if (sel == 'b')
		to = &data->sta;
	if (*to && (*to)->idx == thenbr)
	{
		ft_ps_push(from, data);
		return (1);
	}
	maxidx = minidx + chsize - 1;
	if (maxidx > data->arrayln)
		chsize -= (data->arrayln - 3) % chsize;
	if ((*from)->idx >= minidx && (*from)->idx < minidx + chsize / 2 - 1)
		ft_ps_pushrot(from, to, data);
	else if ((*from)->idx >= minidx + chsize / 2 - 1 && (*from)->idx <= maxidx)
		ft_ps_push(from, data);
	else
		ft_ps_exit(data, UNDEFERR);
	return (1);
}