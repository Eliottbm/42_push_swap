/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:17:49 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/26 16:30:41 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

int	checknum(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0
			&& (str[i] != '+' && str[i] != '-' && str[i] != ' '))
			return (1);
		if ((str[i] == '+' || str[i] == '-')
			&& (((str[i - 1] && str[i - 1] != ' '))
				|| (!str[i + 1] || (str[i + 1]
						&& ft_isdigit(str[i + 1]) == 0))))
			return (1);
		i++;
	}
	return (0);
}

int	add_to_stack(char **str, t_data *data)
{
	t_list	*tmpstack;
	size_t	i;

	i = 0;
	while (str[i])
	{
		tmpstack = ft_lstnew(ft_atoi(str[i]));
		if (!tmpstack)
			return (1);
		ft_lstadd_back(&(data->stack_a), tmpstack);
		i++;
	}
	return (0);
}

int	make_stack(char **str, t_data *data)
{
	char	**tmpsplit;
	size_t	i;

	data->stack_a = NULL;
	data->stack_b = NULL;
	i = 1;
	while (str[i])
	{
		if (checknum(str[i]))
			return (1);
		tmpsplit = ft_split(str[i], ' ');
		if (!tmpsplit)
			return (1);
		if (add_to_stack(tmpsplit, data))
			return (freesplit(tmpsplit), 1);
		freesplit(tmpsplit);
		i++;
	}
	return (0);
}
