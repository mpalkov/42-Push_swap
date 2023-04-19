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
# include <stdlib.h> //to use NULL, atoi
# include <stdio.h> //printf

typedef struct	s_node {
	int				nbr;
	struct s_node	*next;
//	struct s_node	*prev;
}				t_node;


// operations.h
int	ft_swap(t_node **stack);
int	ft_sa(t_node *stack);

#endif
