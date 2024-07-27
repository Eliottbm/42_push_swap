/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:51:54 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/27 22:47:02 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	big_sort_initialize(t_data *data)
{
	data->size = data->size_a;
	data->q1 = data->size / 4 + data->size % 2;
	data->q2 = data->size / 2 + data->size % 2;
	data->q3 = data->size / 4 + data->size / 2 + data->size % 2;
	data->from_ab = 0;
	data->rr_b = 0;
	data->i_b = 0;
	data->is_med = 0;
	data->half_a = 0;
	data->min = NULL;
	data->max = NULL;
}

int	a_to_b2(t_data *data)
{
	data->count = -1;
	if (a_lookup(data, NULL, 0)
		|| a_lookup(data, NULL, 1))
		return (1);
	make_moove(data);
	return (0);
}

int	a_to_b(t_data *data)
{
	while (data->size_b < data->q2)
	{
		if (a_to_b2(data))
			return (1);
		if (data->stack_b && data->stack_b->pos <= data->q1)
			rotate_b(data);
	}
	data->half_a = 1;
	while (data->size_b < data->q3)
		if (a_to_b2(data))
			return (1);
	while (data->size_a > 3)
	{
		if (is_highest3a(data, data->stack_a))
			rotrev_high3a(data);
		push_b(data);
	}
	sort_3elems(data);
	return (0);
}

int	b_to_a(t_data *data)
{
	push_a(data);
	data->from_ab = 1;
	while (data->stack_b)
	{
		data->count = -1;
		if (data->size_a == data->q1)
			data->is_med = 1;
		if (data->size_a == data->q2)
			data->is_med = 2;
		if (data->size_a == data->q3)
			data->is_med = 3;
		if (b_lookup(data, 0)
			|| b_lookup(data, 1))
			return (1);
		make_moove(data);
	}
	return (0);
}

int	big_sort(t_data *data)
{
	t_list	*min_a;
	int		rotrev_a;

	if (get_pos(data))
		return (1);
	big_sort_initialize(data);
	if (a_to_b(data))
		return (1);
	if (b_to_a(data))
		return (1);
	min_a = stack_maxmin(data->stack_a, 0);
	rotrev_a = rot_or_rev(data->stack_a, min_a, data->size_a);
	while (data->stack_a != min_a)
	{
		if (rotrev_a == 0)
			rotate_a(data);
		else
			reverse_a(data);
	}
	return (0);
}
