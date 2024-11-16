/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:30:30 by rohta             #+#    #+#             */
/*   Updated: 2024/11/16 18:56:48 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(s_list **stack_a, s_list **stack_b)
{
	int		tmp_num;
	size_t	tmp_sort;
	s_list	*node_b;

	if (!stack_a || !*stack_a)
		return ;
	tmp_num = *(*stack_a)->num;
	tmp_sort = *(*stack_a)->sort;
	delete_top_node(stack_a);
	node_b = ft_cycle_lstnew(tmp_num, tmp_sort);
	if (!node_b)
		return ;
	if (!stack_b || !*stack_b)
	{
		*stack_b = node_b;
		node_b->next = node_b;
		return ;
	}
	ft_cycle_lstadd_front(stack_b, node_b);
}

void	push_b(s_list **stack_a, s_list **stack_b)
{
	int		tmp_num;
	size_t	tmp_sort;
	s_list	*node_a;
	
	if (!stack_b || !*stack_b)
		return ;
	tmp_num = *(*stack_b)->num;
	tmp_sort = *(*stack_b)->sort;
	delete_top_node(stack_b);
	node_a = ft_cycle_lstnew(tmp_num, tmp_sort);
	if (!node_a)
		return ;
	if (!stack_a || !*stack_a)
	{
		*stack_a = node_a;
		node_a->next = node_a;
		return ;
	}
	ft_cycle_lstadd_front(stack_a, node_a);
}

void	swap_a(s_list **stack_a)
{
	int		tmp_num;
	size_t	tmp_sort;
	size_t	i;
	s_list	*node_1;
	s_list	*node_2;

	if (!stack_a || !*stack_a)
		return ;
	i = 1;
	while (i <= 2)
	{
		tmp_num = *(*stack_a)->num;
		tmp_sort = *(*stack_a)->sort;
		delete_top_node(stack_a);
		if (i == 1)
			node_1 = ft_cycle_lstnew(tmp_num, tmp_sort);
		else
			node_2 = ft_cycle_lstnew(tmp_num, tmp_sort);
		i++;
	}
	ft_cycle_lstadd_front(stack_a, node_1);
	ft_cycle_lstadd_front(stack_a, node_2);
}

void	swap_b(s_list **stack_b)
{
	int		tmp_num;
	size_t	tmp_sort;
	size_t	i;
	s_list	*node_1;
	s_list	*node_2;

	if (!stack_b || !*stack_b)
		return ;
	i = 1;
	while (i <= 2)
	{
		tmp_num = *(*stack_b)->num;
		tmp_sort = *(*stack_b)->sort;
		delete_top_node(stack_b);
		if (i == 1)
			node_1 = ft_cycle_lstnew(tmp_num, tmp_sort);
		else
			node_2 = ft_cycle_lstnew(tmp_num, tmp_sort);
		i++;
	}
	ft_cycle_lstadd_front(stack_b, node_1);
	ft_cycle_lstadd_front(stack_b, node_2);
}

void	swap_swap(s_list **stack_a, s_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	rotate_a(s_list **stack_a)
{
	int	tmp_num;
	size_t	tmp_sort;
	s_list	*node;

	if (!stack_a || !*stack_a)
		return ;
	tmp_num = *(*stack_a)->num;
	tmp_sort = *(*stack_a)->sort;
	delete_top_node(stack_a);
	node = ft_cycle_lstnew(tmp_num, tmp_sort);
	ft_cycle_lstadd_back(stack_a, node);
}

void	ratate_b(s_list **stack_b)
{
	int	tmp_num;
	size_t	tmp_sort;
	s_list	*node;

	if (!stack_b || !*stack_b)
		return ;
	tmp_num = *(*stack_b)->num;
	tmp-sort = *(*stack_b)->sort;
	delete_top_node(stack_b);
	node = ft_cycle_lstnew(tmp_num, tmp_sort);
	ft_cycle_lstadd_back(stack_b, node);
}

void	rotate_rotate(s_list **stack_a, s_list **stack_b)
{
	ratate_a(stack_a);
	rotate_b(stack_b);
}


