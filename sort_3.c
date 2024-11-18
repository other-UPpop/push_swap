/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:11:38 by rohta             #+#    #+#             */
/*   Updated: 2024/11/18 18:51:11 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_one(s_list **stack_a, size_t second, size_t third)
{
	if (second < third)
		return ;
	else
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	return ;
}

void	top_two(s_list **stack_a, size_t first, size_t third)
{
	if (first < third)
		swap_a(stack_a);
	else
		rotate_a(stack_a);
	return ;
}

void	top_three(s_list **stack_a, size_t first, size_t second)
{
	if (first < second)
		reverse_rotate_a(stack_a);
	else
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	return ;
}

void	sort_3(s_list **stack_a)
{
	s_list	*node;
	size_t	first;
	size_t	second;
	size_t	third;
	size_t	i;


	first = *(*stack_a)->sort;
	second = *(*stack_a)->next->sort;
	third = *(*stack_a)->next->next->sort;
	node = *stack_a;
	i = 1;
	printf(("fnode:%ld\n"), first);
	printf(("snode:%ld\n"), second);
	printf(("tnode:%ld\n"), third);
	if (first < second && first < third)
		top_one(stack_a, second, third);
	else if (second < first && second < third)
		top_two(stack_a, first, third);
	else if (third < first && third < second)
		top_three(stack_a, first, second);
	return ;
}
