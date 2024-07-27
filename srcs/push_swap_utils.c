/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:10:32 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/27 21:37:37 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	is_highest3a(t_data *data, t_list *stack)
{
	if (stack->pos == data->size
		|| stack->pos == data->size - 1
		|| stack->pos == data->size - 2)
		return (1);
	return (0);
}

void	rotrev_high3a(t_data *data)
{
	if (is_highest3a(data, data->stack_a)
		&& is_highest3a(data, data->stack_a->next)
		&& is_highest3a(data, ft_lstlast(data->stack_a)) == 0)
		reverse_a(data);
	else
		rotate_a(data);
	if (is_highest3a(data, data->stack_a))
		rotate_a(data);
}

int	rot_or_rev(t_list *stack, t_list *minmax, int stack_size)
{
	t_list	*tmpstack;
	int		i;

	tmpstack = stack;
	i = 0;
	while (tmpstack != minmax)
	{
		tmpstack = tmpstack->next;
		i++;
	}
	if (i >= (stack_size / 2))
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
