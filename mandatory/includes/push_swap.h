/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:05:29 by mpalkov           #+#    #+#             */
/*   Updated: 2023/04/19 15:53:36 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>	// to use NULL, atoi
# include <stdio.h>		// printf
# include "libft.h"
// # include <errno.h>	// errors

enum // ERRORS
{
	OK,			// No error, everything OK
	NO_ACTIONS, // No actions needed, return prompt without pinting
	INPUTERR,	// Error in input data
	MALLOCERR,	// Error on malloc
	WRITEERR,	// Error of a write()
	UNDEFERR,	// Undefined error
};

typedef struct s_node
{
	int				nbr;
	int				idx;
	struct s_node	*next;
	//	struct s_node	*prev;
	// int				listsize;
	// int				chunkid;
	// int				chunksize;
}				t_node;

typedef struct s_vars
{
	int		*sortedarray;
	size_t	arrayln;
	t_node	*sta;
	t_node	*stb;
	size_t	chnum_a;
	size_t	chnum_b;
	t_list	*chunks_a;
	t_list	*chunks_b;
	int		argc;
	char	**argv;
	int		errno; // see enum ERRORS
}				t_vars;

typedef struct s_chunk
{
//	t_node			*start;
	size_t			len;
//	int				in_stack;
	size_t			rra2do;
	struct s_chunk	*next;
}				t_chunk;

// push-swap custom functions
int		ft_addlast(t_node **stack, int n, t_vars *data);
void	ft_printf_int(void *data);
void	ft_ps_lstiter(t_node *lst, void (*f)(void *));

int		ft_ps_digitchecks(char *str, int *i, int *j, int *sign);
int		ft_ps_atoi(char *str, int *nbr, t_vars *data);

int		ft_ps_printerr(int err);
int		ft_ps_error(t_vars *data, int err);

// list_tools.h - can be added to the libft maybe?
t_node	*ft_lst_getlast(t_node *stack);
t_node	*ft_lst_getprelast(t_node *stack);
t_node	*ft_ps_lstfind(t_node *lst, int key);

// operations.h
int		ft_swap(t_node **stack);
int		ft_sa(t_node **stack);
int		ft_rotate(t_node **stack);
int		ft_ra(t_node **stack);
int		ft_revrotate(t_node **stack);
int		ft_push(t_node **from, t_node **to);

#endif