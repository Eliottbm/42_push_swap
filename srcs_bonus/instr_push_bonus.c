/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:54:10 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/23 14:22:37 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

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
	if (data->stack_b)
		push_stack(&(data->stack_b), &(data->stack_a));
}

void	push_b(t_data *data)
{
	if (data->stack_a)
		push_stack(&(data->stack_a), &(data->stack_b));
}
