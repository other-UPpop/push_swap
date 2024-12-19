/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:32:19 by rohta             #+#    #+#             */
/*   Updated: 2024/12/19 16:46:03 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first_push(t_list **stack, t_list *node)
{
	if (!stack || !*stack)
	{
		*stack = node;
		node->next = node;
		node->prev = node;
		return ;
	}
	return ;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	int		tmp_num;
	size_t	tmp_sort;
	t_list	*node_b;

	if (!stack_a || !*stack_a)
		return ;
	ft_printf("pb\n");
	tmp_num = *(*stack_a)->num;
	tmp_sort = *(*stack_a)->sort;
	delete_top_node(stack_a);
	node_b = ft_cycle_lstnew(tmp_num, tmp_sort);
	if (!node_b)
		return ;
	first_push(stack_b, node_b);
	ft_cycle_lstadd_front(stack_b, node_b);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	int		tmp_num;
	size_t	tmp_sort;
	t_list	*node_a;

	if (!stack_b || !*stack_b)
		return ;
	ft_printf("pa\n");
	tmp_num = *(*stack_b)->num;
	tmp_sort = *(*stack_b)->sort;
	delete_top_node(stack_b);
	node_a = ft_cycle_lstnew(tmp_num, tmp_sort);
	if (!node_a)
		return ;
	first_push(stack_a, node_a);
	ft_cycle_lstadd_front(stack_a, node_a);
}
