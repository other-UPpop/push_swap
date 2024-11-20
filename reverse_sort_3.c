/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_sort_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:05:50 by rohta             #+#    #+#             */
/*   Updated: 2024/11/20 16:20:11 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_top_one(t_list **stack_b, size_t second, size_t third)
{
	if (second > third)
		return ;
	else
	{
		swap_b(stack_b);
		rotate_b(stack_b);
	}
	return ;
}

void	re_top_two(t_list **stack_b, size_t first, size_t third)
{
	if (first > third)
		swap_b(stack_b);
	else
		rotate_b(stack_b);
	return ;
}

void	re_top_three(t_list **stack_b, size_t first, size_t second)
{
	if (first > second)
		reverse_rotate_b(stack_b);
	else
	{
		swap_b(stack_b);
		reverse_rotate_b(stack_b);
	}
	return ;
}

void	reverse_sort_3(t_list **stack_b)
{
	size_t	first;
	size_t	second;
	size_t	third;

	first = *(*stack_b)->sort;
	second = *(*stack_b)->next->sort;
	third = *(*stack_b)->next->next->sort;
	if (first > second && first > third)
		re_top_one(stack_b, second, third);
	else if (second > first && second > third)
		re_top_two(stack_b, first, third);
	else if (third > first && third > second)
		re_top_three(stack_b, first, second);
	return ;
}
