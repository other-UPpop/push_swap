/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:40:18 by rohta             #+#    #+#             */
/*   Updated: 2024/12/19 17:12:11 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_6(t_list **stack_a, t_list **stack_b)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		if (!(*(*stack_a)->sort < 4) && *(*stack_a)->next->sort < 4)
			swap_a(stack_a);
		else
		{
			while (*(*stack_a)->sort > 3)
				reverse_rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
		i++;
	}
	sort_3(stack_a);
	reverse_sort_3(stack_b);
	while (i--)
		push_a(stack_a, stack_b);
	return ;
}
