/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:38:03 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/24 15:06:16 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

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
	{
		ft_printf("rra\n");
		reverse_stack(&(data->stack_a));
	}
}

void	reverse_b(t_data *data)
{
	if (data->stack_b)
	{
		ft_printf("rrb\n");
		reverse_stack(&(data->stack_b));
	}
}

void	reverse_both(t_data *data)
{
	if (data->stack_a && data->stack_b)
	{
		ft_printf("rrr\n");
		reverse_stack(&(data->stack_a));
		reverse_stack(&(data->stack_b));
	}
}
