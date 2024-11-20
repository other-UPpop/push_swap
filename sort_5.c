/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:10:34 by rohta             #+#    #+#             */
/*   Updated: 2024/11/20 16:24:58 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	size_t	i;

	i = 0;
	while (i < 2)
	{
		if (!(*(*stack_a)->sort < 3) && *(*stack_a)->next->sort < 3)
			swap_a(stack_a);
		else
		{
			while (*(*stack_a)->sort > 2)
				reverse_rotate_a(stack_a);
		}
		push_a(stack_a, stack_b);
		i++;
	}
	sort_3(stack_a);
	reverse_sort_2(stack_b);
	while (i--)
		push_b(stack_a, stack_b);
	return ;
}
