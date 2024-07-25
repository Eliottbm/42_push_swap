/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:54:10 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/22 17:27:31 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	push_stack(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmpstack;

	if (*stack_from)
	{
		tmpstack = *stack_from;
		if ((*stack_from)->next)
		{
			*stack_from = (*stack_from)->next;
			(*stack_from)->prev = NULL;
		}
		else
			*stack_from = NULL;
		tmpstack->next = NULL;
		ft_lstadd_front(stack_to, tmpstack);
	}
}

void	push_a(t_data *data)
{
	ft_printf("pa\n");
	if (data->stack_b)
	{
		if (!data->min
			|| (data->min && data->stack_b->value < data->min->value))
			data->min = data->stack_b;
		if (!data->max
			|| (data->max && data->stack_b->value > data->max->value))
			data->max = data->stack_b;
		push_stack(&(data->stack_b), &(data->stack_a));
		data->size_a += 1;
		data->size_b -= 1;
	}
}

void	push_b(t_data *data)
{
	ft_printf("pb\n");
	if (data->stack_a)
	{
		push_stack(&(data->stack_a), &(data->stack_b));
		data->size_a -= 1;
		data->size_b += 1;
	}
}
