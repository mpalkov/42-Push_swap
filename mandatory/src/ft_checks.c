#include "push_swap.h"

// CHECK IF NUM REPEATS WITHIN ISSORTED CHECK
int	ft_ps_numrepeats(int *array, unsigned int len, t_var *data)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 1;
	--len;
	while (i < len && j <= len)
	{
		while (j <= len)
		{
			if (array[i] == array[j++])
				ft_ps_exit(data, INPUTERR);
		}
		++i;
		j = i + 1;		
	}
	return (0);
}

// Check if indexes of 2 nodes are sorted in desired order
int	ft_ps_inorder(t_node *cur, int order)
{
	if (order == ASCEND && cur->idx == cur->next->idx - 1)
		return (1);
	else if (order == DESCEND && cur->idx == cur->next->idx + 1)
		return (1);
	return(0);
}

//ORDER 1 == ASCENDING	(WHEN SORTED IN STACK A)
//ORDER 0 == DESCENDING	(WHEN SORTED IN STACK B)
//len - length to check-sort from start
//(start == 1, to compare start + 1 len == 2)
int	ft_ps_sortedcheck(t_node *start, unsigned int len, int order, t_var *data)
{
	unsigned int	i;
	t_node	*cur;
	int		sorted;

	cur = start;
	sorted = 1;
	i = 1;
	if (len == 0)
		len = data->arrayln;
	while (cur && cur->next && sorted && i < len)
	{
		if (ft_ps_inorder(cur, order))
		{
			sorted = 1;
			cur = cur->next;
			++i;
		}
		else
			return (0);
	}	
	return (1);
}

int	ft_ps_digitchecks(char *str, int *i, int *j, int *sign)
{
	while (str[*i] && (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13)))
		++(*i);
	if (str[*i] && (str[*i] == '-' && (str[*i + 1] >= '0' \
			&& str[*i + 1] <= '9')))
		*sign = -1;
	if (str[*i] && ((str[*i] == '+' || str[*i] == '-') \
			&& (str[*i + 1] >= '0' && str[*i + 1] <= '9')))
		++(*i);
	while (str[*i + *j])
	{
		if (str[*i + *j] >= '0' && '9' >= str[*i + *j])
			++(*j);
		else
			return (-1);
	}
	return (1);
}

int	ft_ps_atoi(char *str, int *nbr, t_var *data)
{
	// char *str, int *nbr
	// str[i + 1], array + i
	int		i;
	int		j;
	int		sign;
	long	c;

	i = 0;
	j = 0;
	sign = 1;
	c = 0;
	if (!str || !nbr)
		ft_ps_exit(data, INPUTERR);
		// ERROR - WRONG ATOI INPUT
	if (ft_ps_digitchecks(str, &i, &j, &sign) == -1)
		ft_ps_exit(data, INPUTERR);
	while (--j >= 0)
		c = c * 10 + (str[i++] - '0');
	c = c * sign;
	*nbr = (int)c;
	if (c != *nbr)
		ft_ps_exit(data, INPUTERR);
		// ERROR - INPUT EXCEEDS INT LIMITS
	return (1);
}
