/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:10:32 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/25 11:59:22 by ebengtss         ###   ########.fr       */
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
