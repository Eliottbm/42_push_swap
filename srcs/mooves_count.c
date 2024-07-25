/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:14:58 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/23 12:41:34 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	make_moove2(t_data *data, int i)
{
	if ((data->comp)[i] == 'f')
		rotate_a(data);
	else if ((data->comp)[i] == 'g')
		rotate_b(data);
	else if ((data->comp)[i] == 'h')
		rotate_both(data);
	else if ((data->comp)[i] == 'i')
		reverse_a(data);
	else if ((data->comp)[i] == 'j')
		reverse_b(data);
	else if ((data->comp)[i] == 'k')
		reverse_both(data);
}

void	make_moove(t_data *data)
{
	int		i;

	i = 0;
	while ((data->comp)[i])
	{
		if ((data->comp)[i] == 'a')
			swap_a(data);
		else if ((data->comp)[i] == 'b')
			swap_b(data);
		else if ((data->comp)[i] == 'c')
			swap_both(data);
		else if ((data->comp)[i] == 'd')
			push_a(data);
		else if ((data->comp)[i] == 'e')
			push_b(data);
		else
			make_moove2(data, i);
		i++;
	}
	free(data->comp);
	data->comp = NULL;
}

int	count_moove2(int i_a, int i_b)
{
	int	mvcnt;
	int	imin;

	if (i_a > i_b)
		imin = i_b;
	else
		imin = i_a;
	if (i_a == i_b)
		mvcnt = ((i_a + i_b) / 2) + 1;
	else
		mvcnt = i_a + i_b - imin + 1;
	return (mvcnt);
}

int	count_moove(t_data *data, int bv)
{
	int		mvcnt;

	if (data->rr_a == data->rr_b && data->i_a >= 1 && data->i_b >= 1)
		mvcnt = count_moove2(data->i_a, data->i_b);
	else
		mvcnt = data->i_b + data->i_a + 1;
	mvcnt += data->rr_a + data->rr_b;
	if (data->is_minmax >= 0)
		mvcnt += 1;
	if (mvcnt < data->count || data->count < 0)
	{
		data->count = mvcnt;
		if (build_moove(data, data->i_a, data->i_b, bv))
			return (1);
	}
	return (0);
}
