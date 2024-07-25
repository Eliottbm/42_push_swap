/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:24:19 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/23 12:24:44 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	find_median2(t_data *data, int cmpnodeval)
{
	t_list	*a2;
	int		lowhigh;

	a2 = data->stack_a;
	lowhigh = 0;
	while (a2)
	{
		if (a2->value > cmpnodeval)
			lowhigh += 1;
		else if (a2->value < cmpnodeval)
			lowhigh -= 1;
		a2 = a2->next;
	}
	return (lowhigh);
}

int	find_median(t_data *data)
{
	t_list	*a;
	int		lowhigh;

	a = data->stack_a;
	while (a)
	{
		lowhigh = find_median2(data, a->value);
		if ((data->size_a % 2 != 0 && lowhigh == 0)
			|| (data->size_a % 2 == 0 && (lowhigh == -1 || lowhigh == 1)))
		{
			data->median = a;
			break ;
		}
		a = a->next;
	}
	if (!data->size_a % 2 != 0)
		return ((data->size_a / 2) + (data->size_a % 2));
	return ((data->size_a / 2) + lowhigh);
}
