/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:41:27 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/29 20:07:15 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 1)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (make_stack(av, data))
		return (freelsts(data), ft_putstr_fd("Error\n", 2), 1);
	if (check_sort(data))
	{
		if (data->size_a <= 5)
			small_sort(data);
		else
			if (big_sort(data))
				return (freelsts(data), ft_putstr_fd("Error\n", 2), 1);
	}
	return (freelsts(data), 0);
}
