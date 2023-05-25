#include "push_swap.h"

t_node	*ft_ps_lstfind(t_node *lst, int key)
{
	while (lst)
	{
		if (lst->nbr == key)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_ps_lstiter(t_node *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(&(lst->nbr));
		lst = lst->next;
	}
	return ;
}

int	ft_addlast(t_node **stack, int n, t_var *data)
{
	t_node	*last;
	t_node	*new;

	new = NULL;
	new = malloc(sizeof(*new));
	if (!new)
		ft_ps_exit(data, MALLOCERR);
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