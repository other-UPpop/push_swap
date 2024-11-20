/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:53:19 by rohta             #+#    #+#             */
/*   Updated: 2024/11/20 16:21:20 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	int		tmp_num;
	size_t	tmp_sort;
	t_list	*node;

	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	ft_printf("ra\n");
	tmp_num = *(*stack_a)->num;
	tmp_sort = *(*stack_a)->sort;
	delete_top_node(stack_a);
	node = ft_cycle_lstnew(tmp_num, tmp_sort);
	ft_cycle_lstadd_back(stack_a, node);
}

void	rotate_b(t_list **stack_b)
{
	int		tmp_num;
	size_t	tmp_sort;
	t_list	*node;

	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	ft_printf("rb\n");
	tmp_num = *(*stack_b)->num;
	tmp_sort = *(*stack_b)->sort;
	delete_top_node(stack_b);
	node = ft_cycle_lstnew(tmp_num, tmp_sort);
	ft_cycle_lstadd_back(stack_b, node);
}

static void	rotate_rotate_a(t_list **stack_a)
{
	int		tmp_num;
	size_t	tmp_sort;
	t_list	*node;

	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	tmp_num = *(*stack_a)->num;
	tmp_sort = *(*stack_a)->sort;
	delete_top_node(stack_a);
	node = ft_cycle_lstnew(tmp_num, tmp_sort);
	ft_cycle_lstadd_back(stack_a, node);
}

static void	rotate_rotate_b(t_list **stack_b)
{
	int		tmp_num;
	size_t	tmp_sort;
	t_list	*node;

	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	tmp_num = *(*stack_b)->num;
	tmp_sort = *(*stack_b)->sort;
	delete_top_node(stack_b);
	node = ft_cycle_lstnew(tmp_num, tmp_sort);
	ft_cycle_lstadd_back(stack_b, node);
}

void	rotate_rotate(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	ft_printf("rr\n");
	rotate_rotate_a(stack_a);
	rotate_rotate_b(stack_b);
}
