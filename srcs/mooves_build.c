/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:14:58 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/23 12:42:22 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	build_moove4(t_data *data, int i)
{
	if (data->is_minmax == 0)
		(data->comp)[i++] = 'i';
	if (data->is_minmax == 1)
		(data->comp)[i++] = 'f';
	if (data->from_ab == 0 && data->rr_a == 1)
		(data->comp)[i++] = 'i';
	if (data->from_ab == 1 && data->rr_b == 1)
		(data->comp)[i++] = 'j';
	if (data->from_ab == 0)
		(data->comp)[i++] = 'e';
	else
		(data->comp)[i++] = 'd';
	if (data->from_ab == 1 && data->rr_a == 1)
		(data->comp)[i++] = 'f';
	if (data->from_ab == 0 && data->rr_b == 1)
		(data->comp)[i++] = 'g';
	(data->comp)[i] = '\0';
}

int	build_moove3(t_data *data, int i_a, int i_b, int i)
{
	while (i_a > 0)
	{
		if (data->rr_a == 0)
			(data->comp)[i] = 'f';
		else
			(data->comp)[i] = 'i';
		i_a--;
		i++;
	}
	while (i_b > 0)
	{
		if (data->rr_b == 0)
			(data->comp)[i] = 'g';
		else
			(data->comp)[i] = 'j';
		i_b--;
		i++;
	}
	return (i);
}

int	build_moove2(t_data *data, int i_a, int i_b, int i)
{
	int	imin;

	if (i_a > i_b)
		imin = i_b;
	else
		imin = i_a;
	while (i < imin)
	{
		if (data->rr_a == 0)
			(data->comp)[i] = 'h';
		else
			(data->comp)[i] = 'k';
		i++;
	}
	if (i_a != i_b)
	{
		if (i_a > i_b)
			i = build_moove3(data, (i_a - i_b), 0, i);
		else
			i = build_moove3(data, 0, (i_b - i_a), i);
	}
	return (i);
}

int	build_moove(t_data *data, int i_a, int i_b, int bv)
{
	int		i;

	if (data->comp)
		free(data->comp);
	data->comp = malloc(sizeof(char) * data->count + 1);
	if (!(data->comp))
		return (1);
	i = 0;
	(void)bv;
	if (data->rr_a == data->rr_b && i_a >= 1 && i_b >= 1)
		i = build_moove2(data, i_a, i_b, i);
	else
		i = build_moove3(data, i_a, i_b, i);
	build_moove4(data, i);
	return (0);
}
