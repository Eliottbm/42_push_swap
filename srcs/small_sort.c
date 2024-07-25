/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:45:10 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/18 17:20:16 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	small_sort(t_data *data)
{
	if (data->size_a == 1)
		return ;
	else if (data->size_a == 2)
		sort_2elems(data);
	else if (data->size_a == 3)
		sort_3elems(data);
	else if (data->size_a == 4)
		sort_4elems(data);
	else if (data->size_a == 5)
		sort_5elems(data);
}

void	sort_2elems(t_data *data)
{
	t_list	*a;

	a = data->stack_a;
	if (a->value > a->next->value)
		swap_a(data);
}

void	sort_3elems(t_data *data)
{
	t_list	*a;
	int		fst;
	int		scd;
	int		trd;

	a = data->stack_a;
	fst = a->value;
	scd = a->next->value;
	trd = a->next->next->value;
	if (fst > scd && scd > trd)
	{
		swap_a(data);
		reverse_a(data);
	}
	else if (fst > scd && scd < trd && fst < trd)
		swap_a(data);
	else if (fst > scd && scd < trd && fst > trd)
		rotate_a(data);
	else if (fst < scd && scd > trd && fst < trd)
	{
		swap_a(data);
		rotate_a(data);
	}
	else if (fst < scd && scd > trd && fst > trd)
		reverse_a(data);
}

void	sort_4elems(t_data *data)
{
	t_list	*min_a;
	int		rotrev;

	min_a = stack_maxmin(data->stack_a, 0);
	rotrev = rot_or_rev(data->stack_a, min_a, data->size_a);
	while (data->stack_a != min_a)
	{
		if (rotrev == 0)
			rotate_a(data);
		else
			reverse_a(data);
	}
	push_b(data);
	sort_3elems(data);
	push_a(data);
}

void	sort_5elems(t_data *data)
{
	t_list	*min_a;
	int		rotrev;

	while (data->size_b < 2)
	{
		min_a = stack_maxmin(data->stack_a, 0);
		rotrev = rot_or_rev(data->stack_a, min_a, data->size_a);
		while (data->stack_a != min_a)
		{
			if (rotrev == 0)
				rotate_a(data);
			else
				reverse_a(data);
		}
		push_b(data);
	}
	sort_3elems(data);
	push_a(data);
	push_a(data);
}
