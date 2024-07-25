/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:19:37 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/24 15:07:29 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	swap_stack(t_list **stack)
{
	t_list	*tmpstack;

	if (*stack && (*stack)->next)
	{
		tmpstack = *stack;
		*stack = (*stack)->next;
		tmpstack->prev = *stack;
		if ((*stack)->next)
		{
			(*stack)->next->prev = tmpstack;
			tmpstack->next = (*stack)->next;
		}
		else
			tmpstack->next = NULL;
		(*stack)->prev = NULL;
		(*stack)->next = tmpstack;
	}
}

void	swap_a(t_data *data)
{
	if (data->stack_a)
	{
		ft_printf("sa\n");
		swap_stack(&(data->stack_a));
	}
}

void	swap_b(t_data *data)
{
	if (data->stack_b)
	{
		ft_printf("sb\n");
		swap_stack(&(data->stack_b));
	}
}

void	swap_both(t_data *data)
{
	if (data->stack_a && data->stack_b)
	{
		ft_printf("ss\n");
		swap_stack(&(data->stack_a));
		swap_stack(&(data->stack_b));
	}
}
