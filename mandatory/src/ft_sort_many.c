#include "push_swap.h"

int	ft_ps_sort_many(t_var *data)
{
	int	a;
	int	b;

	if (data->arrayln <= 250)
		data->chunksize = SIZEFOR100;
	else
		data->chunksize = SIZEFOR500;
	data->chunkmin = ft_ps_getminidx(data->sta, data->arrayln);
	a = ft_lstsize((t_list *)data->sta);
	b = 0;
	while (a-- > 3)
	{
		if (b == data->chunksize)
		{
			b = 0;
			data->chunkmin += data->chunksize;
			data->chunkmax += data->chunksize;
		}
		ft_ps_findrange(&data->sta, data->chunksize - b++, data);
	}
	ft_ps_handle3(&data->sta, data);
	b = ft_lstsize((t_list *)data->stb);
	while (b--)
		ft_ps_findrange(&data->stb, 1, data);
	return (0);
}

int	ft_ps_handle_many(t_node **stack, t_var *data)
{
	int	issorted;
	int	order;

	issorted = 0;
	order = ASCEND;
	while (!issorted)
	{
		issorted = ft_ps_sortedcheck(*stack, 0, order, data);
		if (issorted)
			return (1);
		else
			ft_ps_sort_many(data);
	}
	return (0);
}
