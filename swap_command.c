/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:37:41 by rohta             #+#    #+#             */
/*   Updated: 2024/11/20 22:06:15 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	two_node(t_list **stack, t_list **node_1, t_list **node_2)
{
	*stack = *node_1;
	(*node_1)->next = *node_1;
	(*node_1)->prev = *node_1;
	ft_cycle_lstadd_front(stack, *node_2);
	return ;
}

static size_t	tmp_node(t_list **stack, t_list **node_1, t_list **node_2, size_t i)
{
	int		tmp_num;
	size_t	tmp_sort;

	tmp_num = *(*stack)->num;
	tmp_sort = *(*stack)->sort;
	delete_top_node(stack);
	if (i == 1)
		*node_1 = ft_cycle_lstnew(tmp_num, tmp_sort);
	else
		*node_2 = ft_cycle_lstnew(tmp_num, tmp_sort);
	i++;
	return (i);
}

void	swap_a(t_list **stack_a)
{
	size_t	i;
	size_t	lst_size;
	t_list	*node_1;
	t_list	*node_2;

	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	ft_printf("sa\n");
	lst_size = ft_cycle_lstsize(*stack_a);
	i = 1;
	while (i <= 2)
		i = tmp_node(stack_a, &node_1, &node_2, i);
	if (lst_size == 2)
		two_node(stack_a, &node_1, &node_2);
	ft_cycle_lstadd_front(stack_a, node_1);
	ft_cycle_lstadd_front(stack_a, node_2);
}

void	swap_b(t_list **stack_b)
{
	size_t	i;
	size_t	lst_size;
	t_list	*node_1;
	t_list	*node_2;

	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	ft_printf("sb\n");
	lst_size = ft_cycle_lstsize(*stack_b);
	i = 1;
	while (i <= 2)
		i = tmp_node(stack_b, &node_1, &node_2, i);
	if (lst_size == 2)
		two_node(stack_b, &node_1, &node_2);
	ft_cycle_lstadd_front(stack_b, node_2);
}

void	swap_swap(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	ft_printf("ss\n");
	swap_a(stack_a);
	swap_b(stack_b);
}
