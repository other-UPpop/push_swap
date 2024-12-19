/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:43:55 by rohta             #+#    #+#             */
/*   Updated: 2024/12/14 22:25:27 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **stack_a)
{
	if (*(*stack_a)->sort < *(*stack_a)->next->sort)
		return ;
	else
		rotate_a(stack_a);
}

void	reverse_sort_2(t_list **stack_b)
{
	if (*(*stack_b)->sort > *(*stack_b)->next->sort)
		return ;
	else
		rotate_b(stack_b);
}
