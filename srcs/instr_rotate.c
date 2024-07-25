/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:38:03 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/24 15:06:54 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	rotate_stack(t_list **stack)
{
	t_list	*stackstart;

	if (!(*stack)->next)
		return ;
	stackstart = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	ft_lstadd_back(stack, stackstart);
}

void	rotate_a(t_data *data)
{
	if (data->stack_a)
	{
		ft_printf("ra\n");
		rotate_stack(&(data->stack_a));
	}
}

void	rotate_b(t_data *data)
{
	if (data->stack_b)
	{
		ft_printf("rb\n");
		rotate_stack(&(data->stack_b));
	}
}

void	rotate_both(t_data *data)
{
	if (data->stack_a && data->stack_b)
	{
		ft_printf("rr\n");
		rotate_stack(&(data->stack_a));
		rotate_stack(&(data->stack_b));
	}
}
