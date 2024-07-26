/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:57:23 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/26 16:30:15 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

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
		{
			ft_printf("ff:%c\n", str[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	add_to_stack(char **str, t_data *data)
{
	t_list	*tmpstack;
	size_t	i;
	long	tmpnb;

	i = 0;
	while (str[i])
	{
		tmpnb = ft_atoi(str[i]);
		if (tmpnb > 2147483647 || tmpnb < -2147483648)
			return (ft_putstr_fd("Error\n", 2), 1);
		tmpstack = ft_lstnew((int)tmpnb);
		if (!tmpstack)
			return (ft_putstr_fd("Error\n", 2), 1);
		ft_lstadd_back(&(data->stack_a), tmpstack);
		i++;
	}
	data->size_a += i;
	return (0);
}

int	check_double(t_data *data)
{
	t_list	*a;
	t_list	*a2;

	a = data->stack_a;
	while (a)
	{
		a2 = data->stack_a;
		while (a2)
		{
			if (a->value == a2->value && a != a2)
				return (1);
			a2 = a2->next;
		}
		a = a->next;
	}
	return (0);
}

void	stack_initialize(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->comp = NULL;
	data->size_a = 0;
	data->size_b = 0;
}

int	make_stack(char **str, t_data *data)
{
	char	**tmpsplit;
	size_t	i;
	size_t	j;

	stack_initialize(data);
	i = 1;
	while (str[i])
	{
		if (checknum(str[i]))
			return (ft_putstr_fd("Error\n", 2), 1);
		j = 0;
		tmpsplit = ft_split(str[i], ' ');
		if (!tmpsplit)
			return (ft_putstr_fd("Error\n", 2), 1);
		if (add_to_stack(tmpsplit, data))
			return (freesplit(tmpsplit), 1);
		freesplit(tmpsplit);
		i++;
	}
	if (check_double(data))
		return (ft_putstr_fd("Error\n", 2), 1);
	return (0);
}
