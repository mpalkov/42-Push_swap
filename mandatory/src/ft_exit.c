#include "push_swap.h"

int	ft_ps_printerr(int err)
{
	if (err > 1)
		write(STDERR_FILENO, "Error\n", 6);
	return (0);
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

// no write protection after printerr(),
//     becaue after this the program terminates.
int	ft_ps_exit(t_var *data, int err)
{
	data->errno = err;
	ft_ps_freestack(&(data->sta));
	ft_ptr_freenull(&(data->sortedarray));
	ft_ps_printerr(err);
	if (err == OK || err == NO_ACTIONS)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}