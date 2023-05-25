#include "push_swap.h"

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

int	ft_ps_push(t_node **from, t_var *data)
{
	char	sel;
	t_node	**to;

	to = ft_ps_pushsel(*from, data);
	sel = ft_ps_stacksel(*to, data);
	if (ft_push(from, to))
	{
		if (ft_printf("p%c\n", sel) < 0)
			ft_ps_exit(data, WRITEERR);
		return (1);
	}
	return (0);
}