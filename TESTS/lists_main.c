#include "push_swap.h"

t_node	*ft_lst_getlast(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;	
	return (stack);
}

int	ft_stadd_last(t_node *stack, int data)
{
	t_node	*last;
	t_node	*new;

	new = NULL;
		new = malloc(sizeof (*new));
	if (!new)
		return (-1);
	new.nbr = data;
	new.next = NULL;
	if (!stack)
		stack = new;
		return (1);
	last = ft_lst_getlast(stack);

	/*	if (!last)
		ft_errmsg(ERR_NOSTACK);
		FREE AND CLOSE;
	*/
	return (1);
}



t_node	*init_a(int argc, char** argv)
{
	t_node *stack;
	int	i;
	int	nbr;

	i = 1;
	nbr = 0;
	stack = NULL;

	while (i <= argc - 1)
	{
		nbr = atoi(argv[i++]);
		if (ft_stadd_last(stack, nbr) == -1)
			return (NULL);
	}
	return (stack);
}

	// sta == stack_a
	// stb == stack_b
int	main(void)
{
	int		argc = 6;
	char	*argv[] = {"push.c", "3", "1", "7", "2", "4"};

	/* INITCHECKS
	 * 1 - check no duplicate numbers present & isdigit for all numbers
	 * 		before atoi.
	 */

	t_node	*sta;
	t_node	*stb;
	sta = NULL;
	stb = NULL;

	sta = ft_init_a();
	if (!a)
		return (-1);
		// ERROR CREATING STACK A
// CONTUNAR AQUI


	
	
	a = malloc(sizeof(t_stack) * (argc - 1) + 1);
	if (!a)
		return (-1);


	return (0);
}
