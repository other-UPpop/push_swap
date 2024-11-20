/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:11:38 by rohta             #+#    #+#             */
/*   Updated: 2024/11/20 16:23:55 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_one(t_list **stack_a, size_t second, size_t third)
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

void	top_two(t_list **stack_a, size_t first, size_t third)
{
	if (first < third)
		swap_a(stack_a);
	else
		rotate_a(stack_a);
	return ;
}

void	top_three(t_list **stack_a, size_t first, size_t second)
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

void	sort_3(t_list **stack_a)
{
	size_t	first;
	size_t	second;
	size_t	third;

	first = *(*stack_a)->sort;
	second = *(*stack_a)->next->sort;
	third = *(*stack_a)->next->next->sort;
	if (first < second && first < third)
		top_one(stack_a, second, third);
	else if (second < first && second < third)
		top_two(stack_a, first, third);
	else if (third < first && third < second)
		top_three(stack_a, first, second);
	return ;
}
