/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:41:27 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/25 11:43:23 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_putstr_fd("Error\nfailed malloc\n", 2), 1);
	if (ac == 1)
		return (ft_putstr_fd("Error\nnot enough args\n", 2), 1);
	if (make_stack(av, data))
		return (freelsts(data), 1);
	if (check_sort(data))
	{
		if (data->size_a <= 5)
			small_sort(data);
		else
			if (big_sort(data))
				return (1);
	}
	return (freelsts(data), 0);
}
