/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initchecks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:42:15 by mpalkov           #+#    #+#             */
/*   Updated: 2023/05/05 12:44:14 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_ps_error(data, INPUTERR);
		// ERROR - WRONG ATOI INPUT
	if (ft_ps_digitchecks(str, &i, &j, &sign) == -1)
		ft_ps_error(data, INPUTERR);
	while (--j >= 0)
		c = c * 10 + (str[i++] - '0');
	c = c * sign;
	*nbr = (int)c;
	if (c != *nbr)
		ft_ps_error(data, INPUTERR);
		// ERROR - INPUT EXCEEDS INT LIMITS
	return (1);
}
