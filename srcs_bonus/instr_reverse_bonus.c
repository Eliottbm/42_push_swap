/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_reverse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:38:03 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/24 15:02:44 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/push_swap_bonus.h"

void	reverse_stack(t_list **stack)
{
	t_list	*stackend;

	if (!(*stack)->next)
		return ;
	stackend = ft_lstlast(*stack);
	stackend->prev->next = NULL;
	ft_lstadd_front(stack, stackend);
}

void	reverse_a(t_data *data)
{
	if (data->stack_a)
		reverse_stack(&(data->stack_a));
}

void	reverse_b(t_data *data)
{
	if (data->stack_b)
		reverse_stack(&(data->stack_b));
}

void	reverse_both(t_data *data)
{
	if (data->stack_a && data->stack_b)
	{
		reverse_stack(&(data->stack_a));
		reverse_stack(&(data->stack_b));
	}
}
