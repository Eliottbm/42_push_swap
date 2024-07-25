/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:11:53 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/24 15:08:08 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# define PUSH_SWAP_BONUS_H

# include "../libft/incs/libft.h"

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
}			t_data;

void	freelsts(t_data *data);

void	freesplit(char **splitted);

void	push_stack(t_list **stack_from, t_list **stack_to);

void	push_a(t_data *data);

void	push_b(t_data *data);

void	reverse_stack(t_list **stack);

void	reverse_a(t_data *data);

void	reverse_b(t_data *data);

void	reverse_both(t_data *data);

void	rotate_stack(t_list **stack);

void	rotate_a(t_data *data);

void	rotate_b(t_data *data);

void	rotate_both(t_data *data);

void	swap_stack(t_list **stack);

void	swap_a(t_data *data);

void	swap_b(t_data *data);

void	swap_both(t_data *data);

int		add_to_stack(char **str, t_data *data);

int		make_stack(char **str, t_data *data);

int		checknum(char *str);

int		check_sort(t_data *data);

int		exec_instr(t_data *data, char *buff);

int		exec_instr2(t_data *data, char *buff);

int		listen_instr(t_data *data);

#endif