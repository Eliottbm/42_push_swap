/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:37:54 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/27 21:38:07 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	stack_prevnext(t_list *stack, int startend)
{
	int		retval;

	if (startend == 0)
	{
		if (stack->prev)
			retval = stack->prev->value;
		else
			retval = ft_lstlast(stack)->value;
	}
	else
	{
		if (stack->next)
			retval = stack->next->value;
		else
			retval = stack->value;
	}
	return (retval);
}

t_list	*stack_maxmin(t_list *stack, int minmax)
{
	t_list	*tmpstack;
	t_list	*elem;

	tmpstack = stack;
	elem = stack;
	while (tmpstack)
	{
		if ((tmpstack->value <= elem->value && minmax == 0)
			|| (tmpstack->value >= elem->value && minmax == 1))
			elem = tmpstack;
		tmpstack = tmpstack->next;
	}
	return (elem);
}
