#include "push_swap.h"

t_node	*ft_init_stack(t_var *data)
{
	t_node	*stack;
	unsigned int	i;
	
	i = 0;
	stack = NULL;
	while (i <= data->arrayln - 1)
		ft_addlast(&stack, data->sortedarray[i++], data);
	return (stack);
}

int	ft_ps_initdata(int argc, char **argv, t_var *data)
{
	if (argc < 2)
		ft_ps_exit(data, INPUTERR);
	data->arrayln = argc - 1;
	data->argc = argc;
	data->argv = argv;
	data->sortedarray = malloc(sizeof(data->sortedarray) * data->arrayln);
	if (!data->sortedarray)
		ft_ps_exit(data, MALLOCERR);
	return (1);
}

int	ft_ps_data_null(t_var *data)
{
	data->sortedarray = NULL;
	data->arrayln = 0;
	data->sta = NULL;
	data->stb = NULL;
	data->argc = 0;
	data->argv = NULL;
	data->errno = 0;
	data->chunksize = 0;
	data->chunkmax = 0;
	data->chunkmin = 0;
	return (1);
}


int	ft_ps_issorted(int *array, unsigned int len, t_var *data)
{
	unsigned int	i;

	i = 0;
	while (i < len - 1)
	{
		if (array[i] < array[i + 1])
			++i;
		else
			return (0);
	}
	ft_ps_exit(data, NO_ACTIONS);
	return (1);
}

int	ft_ps_initialize(int argc, char **argv, t_var *data)
{
	ft_ps_data_null(data);
	ft_ps_initdata(argc, argv, data);
	ft_fillarr(data->sortedarray, data->arrayln, argv, data);
	if (argc == 2)
		ft_ps_exit(data, NO_ACTIONS);
	ft_ps_numrepeats(data->sortedarray, data->arrayln, data);
	ft_ps_issorted(data->sortedarray, data->arrayln, data);
	data->sta = ft_init_stack(data);
	ft_selection_sort(data->sortedarray, data->arrayln);
	ft_ps_indexnodes(data);
	return (1);
}