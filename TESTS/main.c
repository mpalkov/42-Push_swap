/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:51:49 by mpalkov           #+#    #+#             */
/*   Updated: 2023/04/19 17:19:50 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lst_getlast(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;	
	return (stack);
}

t_node	*ft_lst_getprelast(t_node *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

int	ft_addlast(t_node **stack, int data)
{
	t_node	*last;
	t_node	*new;

	new = NULL;
		new = malloc(sizeof (*new));
	if (!new)
		return (-1);
	new->nbr = data;
	new->next = NULL;
	new->idx = 0;
	last = ft_lst_getlast(*stack);
	if (!last)
	{
		*stack = new;
		return (1);
	}
	last->next = new;
	return (1);
}

t_node	*ft_init_stack(int argc, char** argv)
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
		if (ft_addlast(&stack, nbr) == -1)
			return (NULL);
	}
	return (stack);
}

	// sta == stack_a
	// stb == stack_b

int	ft_fillarr(int *array, size_t len, char **str)
{
	size_t	i;

	i = 0;
	while (i <= len)
	{
		if (ft_ps_atoi(str[i + 1], array + i) == -1)
		{
			return (-1);
		}
		++i;
	}
	return (1);
}

int ft_swap_ints(int *a, int *b)
{
	int	tmp[1];

	tmp[0] = *a;
	*a = *b;
	*b = tmp[0];
	return (1);
}

int	ft_selection_sort(int *array, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	idx;

	i = 0;
	while (i < len)
	{
		idx = i;
		j = i + 1;
		while (j < len)
		{
			if (array[j] < array[idx])
				idx = j;
			++j;
		}
		if (array[idx] < array[i])
			ft_swap_ints(array + i, array + idx);
		++i;
	}
	return(0);
}

int	ft_sortarr(int *array, size_t len)
{
	size_t	i;
	int		sorted;

	i = 0;
	sorted = 0;

	if (len > 1)
	{
		while (sorted == 0)
		{
			sorted = 1;
			while (i < len - 1)
			{
				if (array[i] > array[i + 1])
				{
					ft_swap_ints(array + i, array + i + 1);
					sorted = 0;
				}
				++i;
			}
			i = 0;
		}
	}
	return (1);
}

int	ft_ps_data_null(t_vars *data)
{
	data->sortedarray = NULL;
	data->arrayln = 0;
	data->sta = NULL;
	data->stb = NULL;
	data->chunks_a = 0;
	data->chunks_b = 0;
	data->argc = 0;
	data->argv = NULL;
	return (1);
}

int	ft_ps_initdata(int argc, char **argv, t_vars *data)
{
	if (argc < 2)
		return (-1);
	data->arrayln = argc - 1;
	data->argc = argc;
	data->argv = argv;
	data->sortedarray = malloc(sizeof(data->sortedarray) * data->arrayln);
	if (!data->sortedarray)
		return (-1);
		// MEM-ERROR - TERMINATE
	return (1);
}

int	ft_ps_initialize(int argc, char **argv, t_vars *data)
{
	ft_ps_data_null(data);
	if (ft_ps_initdata(argc, argv, data) == -1)
		return (-1);
		// ERROR - TERMINATE
	if (ft_fillarr(data->sortedarray, data->arrayln, argv) == -1)
		return (-1);
	ft_selection_sort(data->sortedarray, data->arrayln);
	
	return(1);
}

int	main(void)
{
	int		argc = 6;
	char	*argv[] = {"push.c", "1", "2", "3", "4", "5"};
	char	*argvb[] = {"push.c", "11", "12"};

	t_vars	data;

	//put all init and sortarray into one line with its variables etc.
	if (ft_ps_initialize(argv, argc, &data) == -1)
		return(-1);
		//ERROR
	

	sta = ft_init_stack(argc, argv);
	if (!sta)
		return (-1);
		// ERROR CREATING STACK A
// CONTUNAR AQUI

// TESTING
	stb = ft_init_stack(3, argvb);
	t_node	*test1 = ft_init_stack(2, (char *[]){"coco", "99"});
	t_node	*test0 = NULL;
	ft_push(&test0, &test1);
	//wrong 1 or 0 elements stacks.
	printf("a: ");
	ft_lstiter(test1, ft_printf_int);
	printf("\nb: ");
	ft_lstiter(sta, ft_printf_int);
	printf("\n");
	printf("pb\n");
	ft_push(&test1, &sta);
	printf("a: %p", test1);
	ft_lstiter(test1, ft_printf_int);
	printf("\nb: ");
	ft_lstiter(sta, ft_printf_int);
	printf("\n\n");

	return (0);
}
