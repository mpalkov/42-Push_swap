#include "push_swap.h"

void	ft_fr_init(t_node *stack, t_var *data)
{
	char	sel;
		
	sel = ft_ps_stacksel(stack, data);
	if (sel == 'a')
		data->chunkmax = data->chunkmin + data->chunksize - 1;
	 // data->chunkmin = data->chunkmin;
	else if (sel == 'b')
	{
		data->chunkmax = ft_ps_getmaxidx(stack, data->arrayln);
		data->chunkmin = data->chunkmax;
	}
}

int	ft_srchdown(t_node **stack, UINT i, t_var *data)
{
	UINT	j;
	t_node	*curb;
	UINT	stacklen;

	j = 0;
	curb = *stack;
	stacklen = ft_lstsize((t_list *)(*stack));
	while (j++ < stacklen - i)
		curb = curb->next;
	if (curb && (curb)->idx >= data->chunkmin && (curb)->idx <= data->chunkmax \
		&& (curb)->idx < data->arrayln - 2)
	{
		while (i-- > 0)
			ft_ps_rrot(stack, data);
		ft_ps_pushrange (stack, data->chunkmin, data->chunksize, data);
		return (1);
	}
	return (0);
}

int	ft_srchup(t_node **stack, t_node **curt, UINT *i, t_var *data)
{
	*curt = (*curt)->next;
		if (*curt && (*curt)->idx >= data->chunkmin && \
			(*curt)->idx <= data->chunkmax && (*curt)->idx < data->arrayln - 2)
		{
			while (*i > 0)
			{
				ft_ps_rot(stack, data);
				--(*i);
			}
			ft_ps_pushrange (stack, data->chunkmin, data->chunksize, data);
			return (1);
		}
	return (0);
}

// chunkmax - max index of the actual chunk.
// chunkmin for actual chunk will be always the lowest of the whole stack A
int	ft_ps_findrange(t_node **stack, UINT chunksize, t_var *data)
{
	UINT	i;
	UINT	stacklen = ft_lstsize((t_list *)(*stack));
	t_node	*curt;
	
	i = 0;
	ft_fr_init(*stack, data);
	curt = *stack;
	if (chunksize > stacklen)
		chunksize = stacklen;
	
	if (*stack && (*stack)->idx >= data->chunkmin && (*stack)->idx <= \
		data->chunkmax && (*stack)->idx < data->arrayln - 2)
	{
		ft_ps_pushrange (stack, data->chunkmin, data->chunksize, data);
		return (1);
	}
	while (curt && ++i <= stacklen / 2 + 1)
	{
		if (ft_srchup(stack, &curt, &i, data) == 1)
			return (1);
		else if (ft_srchdown(stack, i, data) == 1)
			return (1);
	}
	return (0);
}