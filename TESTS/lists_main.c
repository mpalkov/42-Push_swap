/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_main.c                                       :+:      :+:    :+:   */
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

int	ft_stadd_last(t_node **stack, int data)
{
	t_node	*last;
	t_node	*new;

	new = NULL;
		new = malloc(sizeof (*new));
	if (!new)
		return (-1);
	new->nbr = data;
	new->next = NULL;
	last = ft_lst_getlast(*stack);
	if (!last)
	{
		*stack = new;
		return (1);
	}
	new->prev = last;
	last->next = new;
	return (1);
}

t_node	*ft_init_a(int argc, char** argv)
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
		if (ft_stadd_last(&stack, nbr) == -1)
			return (NULL);
	}
	return (stack);
}

	// sta == stack_a
	// stb == stack_b
int	main(void)
{
	int		argc = 6;
	char	*argv[] = {"push.c", "1", "2", "3", "7", "4"};

	/* INITCHECKS
	 * 1 - check no duplicate numbers present & isdigit for all numbers
	 * 		before atoi.
	 * 2 - check that all the strings are valid int values.
	 * 		// long nbr2check = atoi(argv[2]);
	 * 		// char *str2check = itoa(nbr2check);
	 * 		// if (strncmp(argv[2], str2check) == 0)
	 * 		//  	ok;
	 * 		// else
	 * 		//		error, argv[2] is not a valid int;
	 * 		
	 */

	t_node	*sta;
	t_node	*stb;
	sta = NULL;
	stb = NULL;

	sta = ft_init_a(argc, argv);
	if (!sta)
		return (-1);
		// ERROR CREATING STACK A
// CONTUNAR AQUI
//
// TESTING
	ft_sa(sta);
	return (0);
}
