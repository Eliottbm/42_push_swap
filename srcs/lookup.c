/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:25:06 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/23 12:44:47 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	a_lookup(t_data *data, int bv, int startend)
{
	t_list	*a;

	data->is_minmax = -1;
	data->i_a = 0;
	data->rr_a = startend;
	if (startend == 0)
		a = data->stack_a;
	else
		a = ft_lstlast(data->stack_a);
	while (a && data->i_a <= (data->size_a / 2))
	{
		if (data->from_ab == 1)
			if (which_setup(data, a, bv))
				return (1);
		if (data->from_ab == 0 && a->value < data->median->value)
			if (count_moove(data, a->value))
				return (1);
		if (startend == 0)
			a = a->next;
		else
			a = a->prev;
		data->i_a++;
	}
	return (0);
}

int	b_lookup(t_data *data, int startend)
{
	t_list	*b;

	data->i_b = 0;
	data->rr_b = startend;
	if (startend == 0)
		b = data->stack_b;
	else
		b = ft_lstlast(data->stack_b);
	while (b && data->i_b <= data->size_b / 2)
	{
		if (a_lookup(data, b->value, 0)
			|| a_lookup(data, b->value, 1))
			return (1);
		if (startend == 0)
			b = b->next;
		else
			b = b->prev;
		data->i_b++;
	}
	return (0);
}
