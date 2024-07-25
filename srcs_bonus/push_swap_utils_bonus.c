/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:10:32 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/23 14:37:31 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

int	checknum(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9')
			&& (str[i] != '+' && str[i] != '-' && str[i] != ' '))
			return (1);
		if ((str[i] == '+' || str[i] == '-')
			&& str[i + 1] && ft_isdigit(str[i + 1]) == 0)
			return (1);
		i++;
	}
	return (0);
}
