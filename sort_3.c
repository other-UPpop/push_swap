/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:11:38 by rohta             #+#    #+#             */
/*   Updated: 2024/11/16 20:57:48 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(s_list **stack_a, s_list **stack_b)
{
	s_list	*node = *stack_a;
	size_t	i = 0;

	while (i == *node->sort)
	{
		if (i > 2)
			return ;
		node = node->next;
		i++;
	}	
	if (0 == *(*stack_a)->next->sort)
	{
		push_a(stack_a, stack_b);
		swap_a(stack_a);
		push_b(stack_a, stack_b);
		return ;
	}
}
	//else if (1 == (*stack)->sort)
	
	//else if (2 == (*stack)->sort)
