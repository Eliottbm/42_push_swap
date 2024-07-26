/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:51:54 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/26 16:29:43 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	which_setup(t_data *data, t_list *a, int bv)
{
	int	npv;

	npv = stack_prevnext(a, data->rr_a);
	if (data->is_med == 0 && bv < data->median->value)
		return (0);
	if ((data->rr_a == 0 && a->value >= bv && bv >= npv)
		|| (data->rr_a == 1 && a->value <= bv && bv <= npv))
		if (count_moove(data))
			return (1);
	if ((a == data->min && bv < a->value)
		|| (a == data->max && bv > a->value))
	{
		if (data->rr_a == 1 && bv < a->value)
			data->is_minmax = 0;
		else if (data->rr_a == 0 && bv > a->value)
			data->is_minmax = 1;
		if (count_moove(data))
			return (1);
	}
	return (0);
}

void	big_sort_initialize(t_data *data)
{
	data->medianplace = find_median(data);
	data->from_ab = 0;
	data->rr_b = 0;
	data->i_b = 0;
	data->is_med = 0;
	data->min = NULL;
	data->max = NULL;
}

int	a_to_b(t_data *data)
{
	while (data->size_b < data->medianplace)
	{
		data->is_minmax = -1;
		data->count = -1;
		if (a_lookup(data, -1, 0)
			|| a_lookup(data, -1, 1))
			return (1);
		if (data->count == -1)
			break ;
		make_moove(data);
	}
	while (data->stack_a)
		push_b(data);
	return (0);
}

int	b_to_a(t_data *data)
{
	push_a(data);
	data->from_ab = 1;
	while (data->stack_b)
	{
		data->count = -1;
		if (data->size_a == data->medianplace)
			data->is_med = 1;
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

	big_sort_initialize(data);
	if (a_to_b(data))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (b_to_a(data))
		return (ft_putstr_fd("Error\n", 2), 1);
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
