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

int	ft_ps_indexnodes(t_var *data)
{
	unsigned int	i;
	int		*arr;
	t_node	*tmp;

	i = 1;
	arr = data->sortedarray;
	while(i <= data->arrayln)
	{
		tmp = NULL;
		tmp = ft_ps_lstfind(data->sta, arr[i - 1]);
		if (tmp)
			tmp->idx = i;
		++i;
	}
	return (0);
}

int	ft_ps_sorting(t_var *data)
{
	unsigned int	len;

	len = data->arrayln;
	if (len == 2)
		ft_ps_handle2(&data->sta, data);
	else if (len == 3)
		ft_ps_handle3(&data->sta, data);
	else if (len <= 5)
		ft_ps_handle5(&data->sta, data);
	else
		ft_ps_handle_many(&data->sta, data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	data;

	if (argc == 1)
		return (0);
	ft_ps_initialize(argc, argv, &data);
	ft_ps_sorting(&data);

	if (ft_ps_sortedcheck(data.sta, 0, ASCEND, &data) == 1)
		printf("SORTED OK\n");
	else
		printf("NOT SORTED\n");

	//free everything
	ft_ps_exit(&data, OK);
	return (0);
}