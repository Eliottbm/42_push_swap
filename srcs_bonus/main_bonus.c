/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:11:18 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/26 16:32:09 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (ac == 1)
		return (freelsts(data), 0);
	if (make_stack(av, data))
		return (ft_putstr_fd("Error\n", 2), freelsts(data), 1);
	if (listen_instr(data))
		return (ft_putstr_fd("Error\n", 2), freelsts(data), 1);
	if (check_sort(data) || data->stack_b)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (freelsts(data), 0);
}
