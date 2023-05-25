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
# include <limits.h>	// INT_MAX
# include "libft.h"
# include "ft_printf.h"

# define UINT unsigned int

//define chunk size for stack less than 100 or less than 500 numbers
# define SIZEFOR100 20
# define SIZEFOR500 40

// ASCEND 1 - STACK A - descending stacknums starting from top to down
// DESCEND 0 - STACK B - ascending stacknums starting from top to down
# define ASCEND 1
# define DESCEND 0

// ERRORS
/*
	OK,			// No error, everything OK
	NO_ACTIONS, // No actions needed, return prompt without pinting
	INPUTERR,	// Error in input data
	MALLOCERR,	// Error on malloc
	WRITEERR,	// Error of a write()
	UNDEFERR,	// Undefined error
*/
enum
{
	OK,
	NO_ACTIONS,
	INPUTERR,
	MALLOCERR,
	WRITEERR,
	UNDEFERR,
};

typedef struct s_node
{
	struct s_node	*next;
	int				nbr;
	UINT	idx;
}				t_node;

typedef struct s_var
{
	int				*sortedarray;
	UINT	arrayln;
	t_node			*sta;
	t_node			*stb;
	int				argc;
	char			**argv;
	int				errno;
	int				chunksize;
	UINT			chunkmax;
	UINT			chunkmin;
}				t_var;

// push-swap custom functions
int		ft_addlast(t_node **stack, int n, t_var *data);
void	ft_printf_int(void *data);
void	ft_ps_lstiter(t_node *lst, void (*f)(void *));

int		ft_ps_digitchecks(char *str, int *i, int *j, int *sign);
int		ft_ps_atoi(char *str, int *nbr, t_var *data);

int		ft_ps_printerr(int err);
int		ft_ps_exit(t_var *data, int err);
int		ft_ps_freestack(t_node **stack);

// list_tools.h - can be added to the libft maybe?
t_node	*ft_lst_getlast(t_node *stack);
t_node	*ft_lst_getprelast(t_node *stack);
t_node	*ft_ps_lstfind(t_node *lst, int key);
UINT	ft_ps_getminidx(t_node *stack, UINT len);
UINT	ft_ps_getmaxidx(t_node *stack, UINT len);
int		ft_ps_pushidx(t_node **stack, UINT idx, t_var *data);
int		ft_ps_pushidx100(t_node **stack, UINT idx, t_var *data);
int		ft_ps_findrange(t_node **stack, UINT chunksize, t_var *data);
int		ft_ps_pushrange(t_node **from, UINT minidx, UINT chsize, t_var *data);

// operations.h
int		ft_swap(t_node **stack);
int		ft_rotate(t_node **stack);
int		ft_revrotate(t_node **stack);
int		ft_push(t_node **from, t_node **to);

int		ft_ps_swap(t_node **stack, t_var *data);
int		ft_ps_rot(t_node **stack, t_var *data);
int		ft_ps_rrot(t_node **stack, t_var *data);
int		ft_ps_push(t_node **from, t_var *data);

char	ft_ps_stacksel(t_node *stack, t_var *data);
int		ft_ps_ordersel(t_node *stack, t_var *data);

int		ft_ps_handle2(t_node **stack, t_var *data);
int		ft_ps_handle3(t_node **stack, t_var *data);
int		ft_ps_handle5(t_node **stack, t_var *data);
int		ft_ps_handle_many(t_node **stack, t_var *data);

int	ft_ps_sortedcheck(t_node *start, UINT len, int order, t_var *data);
int	ft_ps_initialize(int argc, char **argv, t_var *data);
int	ft_ps_indexnodes(t_var *data);

//arraysort
int	ft_selection_sort(int *array, UINT len);
int	ft_ps_numrepeats(int *array, UINT len, t_var *data);
int	ft_fillarr(int *array, UINT len, char **str, t_var *data);
t_node	**ft_ps_pushsel(t_node *from, t_var *data);

#endif