/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:38:22 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/24 14:58:00 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

void	freelsts(t_data *data)
{
	if (data)
	{
		if (data->stack_a)
			ft_lstclear(&(data->stack_a));
		if (data->stack_b)
			ft_lstclear(&(data->stack_b));
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
