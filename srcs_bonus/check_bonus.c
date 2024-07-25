/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:14:51 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/25 11:57:56 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

int	listen_instr(t_data *data)
{
	char	*buff;

	buff = ft_get_next_line(0);
	while (buff)
	{
		if (exec_instr(data, buff))
		{
			free(buff);
			return (1);
		}
		buff = ft_get_next_line(0);
	}
	free(buff);
	return (0);
}

int	exec_instr2(t_data *data, char *buff)
{
	if (ft_strncmp(buff, "ra\n", ft_strlen(buff)) == 0)
		rotate_a(data);
	else if (ft_strncmp(buff, "rb\n", ft_strlen(buff)) == 0)
		rotate_b(data);
	else if (ft_strncmp(buff, "rr\n", ft_strlen(buff)) == 0)
		rotate_both(data);
	else if (ft_strncmp(buff, "rra\n", ft_strlen(buff)) == 0)
		reverse_a(data);
	else if (ft_strncmp(buff, "rrb\n", ft_strlen(buff)) == 0)
		reverse_b(data);
	else if (ft_strncmp(buff, "rrr\n", ft_strlen(buff)) == 0)
		reverse_both(data);
	else
		return (1);
	return (0);
}

int	exec_instr(t_data *data, char *buff)
{
	if (ft_strncmp(buff, "sa\n", ft_strlen(buff)) == 0)
		swap_a(data);
	else if (ft_strncmp(buff, "sb\n", ft_strlen(buff)) == 0)
		swap_b(data);
	else if (ft_strncmp(buff, "ss\n", ft_strlen(buff)) == 0)
		swap_both(data);
	else if (ft_strncmp(buff, "pa\n", ft_strlen(buff)) == 0)
		push_a(data);
	else if (ft_strncmp(buff, "pb\n", ft_strlen(buff)) == 0)
		push_b(data);
	else
		if (exec_instr2(data, buff))
			return (1);
	return (0);
}

int	check_sort(t_data *data)
{
	t_list	*a;

	a = data->stack_a;
	if (!a)
		return (1);
	while (a)
	{
		if (a->next && a->next->value < a->value)
			return (1);
		a = a->next;
	}
	return (0);
}
