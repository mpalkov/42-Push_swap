#include "push_swap.h"

char	ft_ps_stacksel(t_node *stack, t_var *data)
{
	if (stack == data->sta)
		return ('a');
	if (stack == data->stb)
		return ('b');
	ft_ps_exit(data, UNDEFERR);
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
	ft_ps_exit(data, UNDEFERR);
	return(0);
}

t_node	**ft_ps_pushsel(t_node *from, t_var *data)
{
	if (ft_ps_stacksel(from, data) == 'a')
		return (&data->stb);
	else if (ft_ps_stacksel(from, data) == 'b')
		return (&data->sta);
	else
		ft_ps_exit(data, UNDEFERR);
	return (NULL);
}