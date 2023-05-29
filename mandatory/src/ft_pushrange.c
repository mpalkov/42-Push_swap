/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushrange.c                                     :+:      :+:    :+:   */
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
