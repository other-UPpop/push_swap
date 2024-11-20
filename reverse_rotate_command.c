/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:56:29 by rohta             #+#    #+#             */
/*   Updated: 2024/11/20 16:18:23 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **stack_a)
{
	int		tmp_num;
	size_t	tmp_sort;
	t_list	*last_node;
	t_list	*node;

	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	printf("rra\n");
	last_node = *stack_a;
	last_node = ft_cycle_lstlast(*stack_a);
	tmp_num = *last_node->num;
	tmp_sort = *last_node->sort;
	delete_end_node(stack_a);
	node = ft_cycle_lstnew(tmp_num, tmp_sort);
	ft_cycle_lstadd_front(stack_a, node);
}

void	reverse_rotate_b(t_list **stack_b)
{
	int		tmp_num;
	size_t	tmp_sort;
	t_list	*last_node;
	t_list	*node;

	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	printf("rrb\n");
	last_node = *stack_b;
	last_node = ft_cycle_lstlast(*stack_b);
	tmp_num = *last_node->num;
	tmp_sort = *last_node->sort;
	delete_end_node(stack_b);
	node = ft_cycle_lstnew(tmp_num, tmp_sort);
	ft_cycle_lstadd_front(stack_b, node);
}

static void	reverse_rotate_rotate_a(t_list **stack_a)
{
	int		tmp_num;
	size_t	tmp_sort;
	t_list	*last_node;
	t_list	*node;

	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	last_node = *stack_a;
	last_node = ft_cycle_lstlast(*stack_a);
	tmp_num = *last_node->num;
	tmp_sort = *last_node->sort;
	delete_end_node(stack_a);
	node = ft_cycle_lstnew(tmp_num, tmp_sort);
	ft_cycle_lstadd_front(stack_a, node);
}

static void	reverse_rotate_rotate_b(t_list **stack_b)
{
	int		tmp_num;
	size_t	tmp_sort;
	t_list	*last_node;
	t_list	*node;

	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	last_node = *stack_b;
	last_node = ft_cycle_lstlast(*stack_b);
	tmp_num = *last_node->num;
	tmp_sort = *last_node->sort;
	delete_end_node(stack_b);
	node = ft_cycle_lstnew(tmp_num, tmp_sort);
	ft_cycle_lstadd_front(stack_b, node);
}

void	reverse_rotate_rotate(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	printf("rrr\n");
	reverse_rotate_rotate_a(stack_a);
	reverse_rotate_rotate_b(stack_b);
}
