/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:42:11 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/27 22:42:37 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/incs/libft.h"

typedef struct s_data
{
	int		i_a;
	int		i_b;
	int		rr_a;
	int		rr_b;
	int		size;
	int		size_a;
	int		size_b;
	int		is_minmax;
	int		is_med;
	int		count;
	int		from_ab;
	int		q1;
	int		q2;
	int		q3;
	int		half_a;
	char	*comp;
	t_list	*min;
	t_list	*max;
	t_list	*stack_a;
	t_list	*stack_b;
}			t_data;

t_list	*stack_maxmin(t_list *stack, int minmax);

t_list	*clone_stack(t_data *data);

t_list	*sort_clone(t_data *data);

void	freesplit(char **splitted);

void	freelsts(t_data *data);

void	swap_stack(t_list **stack);

void	swap_a(t_data *data);

void	swap_b(t_data *data);

void	swap_both(t_data *data);

void	push_stack(t_list **stack_from, t_list **stack_to);

void	push_a(t_data *data);

void	push_b(t_data *data);

void	rotate_stack(t_list **stack);

void	rotate_a(t_data *data);

void	rotate_b(t_data *data);

void	rotate_both(t_data *data);

void	reverse_stack(t_list **stack);

void	reverse_a(t_data *data);

void	reverse_b(t_data *data);

void	reverse_both(t_data *data);

void	small_sort(t_data *data);

void	sort_2elems(t_data *data);

void	sort_3elems(t_data *data);

void	sort_4elems(t_data *data);

void	sort_5elems(t_data *data);

void	make_moove(t_data *data);

void	make_moove2(t_data *data, int i);

void	build_moove4(t_data *data, int i);

void	big_sort_initialize(t_data *data);

void	stack_initialize(t_data *data);

void	rotrev_high3a(t_data *data);

int		get_pos(t_data *data);

int		checknum(char *str);

int		check_double(t_data *data);

int		stack_prevnext(t_list *stack, int startend);

int		which_setup(t_data *data, t_list *a, t_list *b);

int		a_lookup(t_data *data, t_list *b, int startend);

int		b_lookup(t_data *data, int startend);

int		big_sort(t_data *data);

int		make_stack(char **str, t_data *data);

int		add_to_stack(char **str, t_data *data);

int		count_moove(t_data *data);

int		count_moove2(int i_a, int i_b);

int		build_moove(t_data *data, int i_a, int i_b);

int		build_moove2(t_data *data, int i_a, int i_b, int i);

int		build_moove3(t_data *data, int i_a, int i_b, int i);

int		rot_or_rev(t_list *stack, t_list *minmax, int stack_size);

int		a_to_b(t_data *data);

int		b_to_a(t_data *data);

int		check_sort(t_data *data);

int		is_highest3a(t_data *data, t_list *stack);

#endif
