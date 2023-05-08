#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_list
{
    void            *content;
    struct s_list    *next;
}                t_list;

typedef struct s_node
{
    int                nbr;
    int                idx;
}                t_node;

t_list  *ft_lstnew(void *content)
{
    struct s_list   *mylist;

    mylist = (t_list *)malloc(sizeof(*mylist));
    if (!mylist)
        return (0);
    mylist->content = content;
    mylist->next = NULL;
    return (mylist);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list    *temp;

    if (!(*lst))
        *lst = new;
    else
    {
        temp = *lst;
        while (temp->next)
            temp = temp->next;
        temp->next = new;
    }
}

int main(void)
{
	t_list  *stack;
    t_node  node1;
    t_node  node2;
    t_node  node3;
    
    node1.nbr = 1;
    node1.idx = 1111;
    node2.nbr = 2;
    node2.idx = 2222;
    node3.nbr = 3;
    node3.idx = 3333;
    
    stack = NULL;
    t_list  *a = ft_lstnew(&node1);
    t_list  *b = ft_lstnew(&node2);
    t_list  *c = ft_lstnew(&node3);

    ft_lstadd_back(&stack, a);
    ft_lstadd_back(&stack, b);
    ft_lstadd_back(&stack, c);
        
    return (0);
}

/*
USE GENERIC libft LIST_FUNCTIONS FOR USE ANY STRUCTURE AS DATA OF THE LIST NODE.
*/