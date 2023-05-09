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

int	ft_ps_printerr(int err)
{
	if (err > 1)
		write(STDERR_FILENO, "Error\n", 6);
	// write(STDOUT_FILENO, "\n", 1);
	return (0);
}

int	ft_ps_error(t_vars *data, int err)
{
	data->errno = err;
	ft_ptr_freenull(&(data->sortedarray));
	ft_ptr_freenull(&(data->sta));
	ft_ptr_freenull(&(data->stb));
	ft_ps_printerr(err);
	// no write protection here, becaue after this the program terminates.
	if (err == OK || err == NO_ACTIONS)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

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

int	ft_addlast(t_node **stack, int n, t_vars *data)
{
	t_node	*last;
	t_node	*new;

	new = NULL;
	new = malloc(sizeof(*new));
	if (!new)
		ft_ps_error(data, MALLOCERR);
	new->nbr = n;
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

t_node	*ft_init_stack(t_vars *data)
{
	t_node	*stack;
	size_t	i;
	
	i = 0;
	stack = NULL;
	while (i <= data->arrayln - 1)
		ft_addlast(&stack, data->sortedarray[i++], data);
	return (stack);
}

// sta == stack_a
// stb == stack_b

int	ft_fillarr(int *array, size_t len, char **str, t_vars *data)
{
	// int *array, size_t len, char **str
	// data->sortedarray, data->arrayln, argv
	size_t	i;

	i = 0;
	while (i < len)
	{
		ft_ps_atoi(str[i + 1], array + i, data);
		++i;
	}
	return (1);
}

int	ft_swap_ints(int *a, int *b)
{
	int tmp[1];

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
	return (0);
}

/* BUBBLE SORT
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
*/

int	ft_ps_data_null(t_vars *data)
{
	data->sortedarray = NULL;
	data->arrayln = 0;
	data->sta = NULL;
	data->stb = NULL;
	data->chunks_a = NULL;
	data->chunks_b = NULL;
	data->chnum_a = 0;
	data->chnum_b = 0;
	data->argc = 0;
	data->argv = NULL;
	data->errno = 0;
	return (1);
}

int	ft_ps_initdata(int argc, char **argv, t_vars *data)
{
	if (argc < 2)
		ft_ps_error(data, INPUTERR);
	data->arrayln = argc - 1;
	data->argc = argc;
	data->argv = argv;
	data->sortedarray = malloc(sizeof(data->sortedarray) * data->arrayln);
	if (!data->sortedarray)
		ft_ps_error(data, MALLOCERR);
		// MEM-ERROR - free and TERMINATE
	return (1);
}

// CHECK IF NUMREPEATS WITHIN ISSORTED CHECK
int	ft_ps_numrepeats(int *array, size_t len, t_vars *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	--len;
	while (i < len && j <= len)
	{
		while (j <= len)
		{
			if (array[i] == array[j++])
				ft_ps_error(data, INPUTERR);
		}
		++i;
		j = i + 1;		
	}
	return (0);
}

int	ft_ps_issorted(int *array, size_t len, t_vars *data)
{
	size_t	i;

	i = 0;
	while (i < len - 1)
	{
		if (array[i] < array[i + 1])
			++i;
		else
			return (0);
	}
	ft_ps_error(data, NO_ACTIONS);
	return (1);
}

int	ft_ps_indexnodes(t_vars *data)
{
	size_t	i;
	int		*arr;
	t_node	*tmp;

	i = 1;
	arr = data->sortedarray;
	while(i <= data->arrayln)
	{
		tmp = NULL;
		tmp = ft_ps_lstfind(data->sta, arr[data->arrayln - i]);
		if (tmp)
			tmp->idx = i;
		++i;
	}
	return (0);
}

int	ft_ps_chunk_null(t_chunk *chn)
{
	chn->len = 0;
	chn->rra2do = 0;
	chn->next = NULL;
	return(0);
}

int	ft_ps_chunk_add(t_chunk **where, t_chunk *start, size_t count, t_vars *data)
{
	t_chunk	*new;

	if (!start || !count || !data)
		ft_ps_error(data, UNDEFERR);

	new = malloc(sizeof(*new));
	if (!new)
		ft_ps_error(data, MALLOCERR);
	ft_ps_chunk_null(new);
	new->len = count;
	new->next = *where;
	*where = new;
	return(0);
}

// CREATE FT_PS_CHUNK_MOD AND FT_PS_CHUNK_SPLIT AND FT_PS_CHUNK_MV

int ft_ps_initialize(int argc, char **argv, t_vars *data)
{
	ft_ps_data_null(data);
	ft_ps_initdata(argc, argv, data);
	ft_fillarr(data->sortedarray, data->arrayln, argv, data);

		// # INITCHECKS START
	// if only 1 number and it's valid int,
	// consider stack as ordered and do nothing.
	if (argc == 2)
		ft_ps_error(data, NO_ACTIONS);

	// IF HAS DUPLICATE NUMBERS, EXIT AND ERROR
	ft_ps_numrepeats(data->sortedarray, data->arrayln, data);
	
	// IF STACK IS SORTED ON INPUT, EXIT WITHOUT PRINTING.
	ft_ps_issorted(data->sortedarray, data->arrayln, data);
		// # INITCHECKS END

	// CREATE THE STACK A
	data->sta = ft_init_stack(data);
	
	ft_selection_sort(data->sortedarray, data->arrayln);

	// ADD INDEX INFORMATION TO EACH LIST NODE
	ft_ps_indexnodes(data);
	return (1);
}

/*
int	ft_ps_sorting(t_vars *data)
{
	size_t	chunkln_a;
	//size_t	chunkln_b;

	chunkln_a = ft_lstsize((t_list *)(data->chunks_a))
	ft_ps_chunk_add(&(data->chunks_a), data->sta, data->arrayln, data);

	//chunks from stA to stB
	while(chunkln_a)
	{
		// ft_ps_issorted stA
		if (chunkln_a = 1)
		{
			
		}
		else if (chunkln_a = 2)
		{
			// ft_sort2;
		}
		else if (chunkln_a = 3)
			// ft_sort3;

		ft_ps_chunk_split(&(data->chunks_a), &(data->chunks_b),  )
	}

	return (0);
}
*/

int	main(int argc, char **argv)
{
	// int		argc = 6;
	// char	*argv[] = {"push.c", "1", "2", "3", "4", "5"};
	// char	*argvb[] = {"push.c", "11", "12"};

	t_vars	data;
	if (argc == 1)
		return (0);

	// put all init and sortarray into one line with its variables etc.
	if (ft_ps_initialize(argc, argv, &data) == -1)
		return (-1);
	// ERROR

	// 	sta = ft_init_stack(argc, argv);
	// 	if (!sta)
	// 		return (-1);
	// 		// ERROR CREATING STACK A
	// // CONTINUAR AQUI

	// // TESTING
	// 	stb = ft_init_stack(3, argvb);
	// 	t_node	*test1 = ft_init_stack(2, (char *[]){"coco", "99"});
	// 	t_node	*test0 = NULL;
	// 	ft_push(&test0, &test1);
	// 	//wrong 1 or 0 elements stacks.
	// 	printf("a: ");
	// 	ft_lstiter(test1, ft_printf_int);
	// 	printf("\nb: ");
	// 	ft_lstiter(sta, ft_printf_int);
	// 	printf("\n");
	// 	printf("pb\n");
	// 	ft_push(&test1, &sta);
	// 	printf("a: %p", test1);
	// 	ft_lstiter(test1, ft_printf_int);
	// 	printf("\nb: ");
	// 	ft_lstiter(sta, ft_printf_int);
	// 	printf("\n\n");
	return (0);
}
