/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:10:46 by eliott            #+#    #+#             */
/*   Updated: 2024/07/27 17:18:21 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_list	*clone_stack(t_data *data)
{
	t_list	*a;
	t_list	*clonestack;
	t_list	*tmpelem;

	a = data->stack_a;
	clonestack = NULL;
	while (a)
	{
		tmpelem = ft_lstnew(a->value);
		if (!tmpelem)
			return (NULL);
		ft_lstadd_back(&clonestack, tmpelem);
		a = a->next;
	}
	return (clonestack);
}

t_list	*sort_clone(t_data *data)
{
	t_list	*clonestack;
	t_list	*tmpstack;
	t_list	*tmpstack2;
	int		tmp;

	clonestack = clone_stack(data);
	tmpstack = clonestack;
	if (!tmpstack)
		return (NULL);
	while (tmpstack)
	{
		tmpstack2 = ft_lstlast(tmpstack);
		while (tmpstack2)
		{
			if (tmpstack2->prev && tmpstack2->prev->value > tmpstack2->value)
			{
				tmp = tmpstack2->value;
				tmpstack2->value = tmpstack2->prev->value;
				tmpstack2->prev->value = tmp;
			}
			tmpstack2 = tmpstack2->prev;
		}
		tmpstack = tmpstack->next;
	}
	return (clonestack);
}

int	get_pos(t_data *data)
{
	t_list	*clonestack;
	t_list	*tmpstack;
	t_list	*a;
	int		i;

	clonestack = sort_clone(data);
	if (!clonestack)
		return (1);
	tmpstack = clonestack;
	i = 1;
	while (tmpstack)
	{
		a = data->stack_a;
		while (a)
		{
			if (a->value == tmpstack->value)
				a->pos = i;
			a = a->next;
		}
		tmpstack = tmpstack->next;
		i++;
	}
	ft_lstclear(&clonestack);
	return (0);
}
