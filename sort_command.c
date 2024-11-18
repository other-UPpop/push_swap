/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   sort_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:30:30 by rohta             #+#    #+#             */
/*   Updated: 2024/11/18 17:10:08 by rohta            ###   ########.fr       */
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
	printf("pa\n");
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
	printf("pb\n");
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
	size_t	lst_size;
	s_list	*node_1;
	s_list	*node_2;

	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	printf("sa\n");
	lst_size = ft_cycle_lstsize(*stack_a);
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
	if (lst_size == 2)
	{
		*stack_a = node_1;
		node_1->next = node_1;
		ft_cycle_lstadd_front(stack_a, node_2);
		return ;
	}
	ft_cycle_lstadd_front(stack_a, node_1);
	ft_cycle_lstadd_front(stack_a, node_2);
}

void	swap_b(s_list **stack_b)
{
	int		tmp_num;
	size_t	tmp_sort;
	size_t	i;
	size_t	lst_size;
	s_list	*node_1;
	s_list	*node_2;

	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	printf("sb\n");
	i = 1;
	lst_size = ft_cycle_lstsize(*stack_b);
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
	if (lst_size == 2)
	{
		*stack_b = node_1;
		node_1->next = node_1;
		ft_cycle_lstadd_front(stack_b, node_2);
		return ;
	}
	ft_cycle_lstadd_front(stack_b, node_1);
	ft_cycle_lstadd_front(stack_b, node_2);
}

void	swap_swap(s_list **stack_a, s_list **stack_b)
{
	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	swap_a(stack_a);
	swap_b(stack_b);
}

void	rotate_a(s_list **stack_a)
{
	int	tmp_num;
	size_t	tmp_sort;
	s_list	*node;

	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	printf("ra\n");
	tmp_num = *(*stack_a)->num;
	tmp_sort = *(*stack_a)->sort;
	delete_top_node(stack_a);
	node = ft_cycle_lstnew(tmp_num, tmp_sort);
	ft_cycle_lstadd_back(stack_a, node);
}

void	rotate_b(s_list **stack_b)
{
	int	tmp_num;
	size_t	tmp_sort;
	s_list	*node;

	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	printf("rb\n");
	tmp_num = *(*stack_b)->num;
	tmp_sort = *(*stack_b)->sort;
	delete_top_node(stack_b);
	node = ft_cycle_lstnew(tmp_num, tmp_sort);
	ft_cycle_lstadd_back(stack_b, node);
}

void	rotate_rotate(s_list **stack_a, s_list **stack_b)
{
	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	reverse_rotate_a(s_list **stack_a)
{
	int	tmp_num;
	size_t	tmp_sort;
	s_list	*last_node;
	s_list	*node;

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

void	reverse_rotate_b(s_list **stack_b)
{
	int	tmp_num;
	size_t	tmp_sort;
	s_list	*last_node;
	s_list	*node;

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

void	reverse_rotate_rotate(s_list **stack_a, s_list **stack_b)
{
	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return ;
	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return ;
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
