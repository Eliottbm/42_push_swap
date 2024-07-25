/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:38:22 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/18 13:40:34 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	freelsts(t_data *data)
{
	if (data)
	{
		if (data->stack_a)
			ft_lstclear(&(data->stack_a));
		if (data->stack_b)
			ft_lstclear(&(data->stack_b));
		if (data->comp)
			free(data->comp);
		free(data);
	}
}

void	freesplit(char **splitted)
{
	size_t	i;

	i = 0;
	if (*splitted)
	{
		while (splitted[i])
		{
			free(splitted[i]);
			i++;
		}
		free(splitted);
	}
}
