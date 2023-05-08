/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_general_fns.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:26:44 by mpalkov           #+#    #+#             */
/*   Updated: 2023/05/08 14:27:00 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* HOW TO USE GENERAL LINKED LIST FUNCTIONS (t_list format)
 * with any data-structure type;
 */


# include <stdlib.h>	// to use NULL, atoi
# include <stdio.h>		// printf

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_node
{
	int				nbr;
	int				idx;
}				t_node;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_ptr_freenull(void *x_ptr);
int		ft_printf(const char *str, ...);

int	main(void)
{
	t_node	nodea;
	t_node	nodeb;
	t_node	nodec;
	t_node	noded;

	t_list	list1;
	t_list	list2;
	t_list	list3;
	t_list	list4;

	nodea.nbr = 42;
	nodea.idx = 9;
	nodeb.nbr = -5;
	nodeb.idx = 0;
	nodea.nbr = 111;
	nodea.idx = 222;
	nodeb.nbr = 3333;
	nodeb.idx = 4444;

	list1.content = &nodea;
	list2.content = &nodeb;
	list1.content = &nodec;
	list2.content = &noded;

	list1.next = &list2;
	list2.next = &list3;
	list3.next = &list4;
	list4.next = NULL;

	return (0);

}







