/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:23:36 by rohta             #+#    #+#             */
/*   Updated: 2024/11/26 19:05:33 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	else_var(t_list **stack_b, t_list *node, size_t found)
{
	size_t	i;

	node = *stack_b;
	i = 1;
	while (*node->sort != found)
	{
		node = node->next;
		i++;
	}
	while (*(*stack_b)->sort != found)
	{
		if (i > found / 2)
			reverse_rotate_b(stack_b);
		else
			rotate_b(stack_b);
	}
}

static void	comp_sort(t_list **stack_a, t_list **stack_b, size_t found,
		size_t ac)
{
	t_list	*node;
	
	node = *stack_b;
	while (ft_cycle_lstsize(*stack_a) != ac || found != 0)
	{
		if (*(*stack_b)->sort == found)
		{
			push_b(stack_a, stack_b);
			found--;
		}
		else
			else_var(stack_b, node, found);
	}
}

static void	cycle_sort(t_list **stack_a, t_list **stack_b)
{
	if (stack_b && *stack_b && ft_cycle_lstsize(*stack_b) >= 2
		&& *(*stack_b)->sort % 2 == 0)
		rotate_rotate(stack_a, stack_b);
	else
		rotate_a(stack_a);
}

static size_t	sort_push_a(t_list **stack_a, t_list **stack_b, size_t large,
		size_t ac)
{
	if ((*(*stack_a)->sort <= large) && !(*(*stack_a)->sort > ac - 2))
	{
		push_a(stack_a, stack_b);
		if (large <= ac - 3)
			large++;
	}
	return (large);
}

void	sort_500(t_list **stack_a, t_list **stack_b, size_t ac)
{
	size_t	large;

	large = 20;
	while (ft_cycle_lstsize(*stack_a) != 3)
	{
		large = sort_push_a(stack_a, stack_b, large, ac);
		if (ft_cycle_lstsize(*stack_a) != 3)
		{
			while (*(*stack_a)->sort > large || *(*stack_a)->sort > ac-3)
				cycle_sort(stack_a, stack_b);
		}
	}
	sort_3(stack_a);
	comp_sort(stack_a, stack_b, ac-3, ac);
}
