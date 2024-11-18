/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:26:02 by rohta             #+#    #+#             */
/*   Updated: 2024/11/18 18:56:06 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(s_list **stack_a, s_list **stack_b)
{
	size_t	i;
	s_list	*node;

	i = 0;
	node = *stack_a;
	if (*(*stack_a)->next->sort == 1)
		swap_a(stack_a);
	else
	{
		while (*(*stack_a)->sort != 1)
			reverse_rotate_a(stack_a);
	}
	push_a(stack_a, stack_b);
	sort_3(stack_a);
	push_b(stack_a, stack_b);
	return ;
}
