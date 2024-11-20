/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:23:36 by rohta             #+#    #+#             */
/*   Updated: 2024/11/20 22:37:23 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cycle_listb(t_list *lst)
{
	t_list	*first;
	t_list	*tmp;

	if (!lst)
		return ;
	first = lst;
	printf("out_num:%d\n", *lst->num);
	lst = lst->next;
	while (lst != first)
	{
		tmp = lst;
		printf("out_num:%d\n", *tmp->num);
		lst = lst->next;
	}
}

void	print_cycle_lista(t_list *lst)
{
	t_list	*first;
	t_list	*tmp;

	if (!lst)
		return ;
	first = lst;
	printf("in_num:%d\n", *lst->num);
	lst = lst->next;
	while (lst != first)
	{
		tmp = lst;
		printf("in_num:%d\n", *tmp->num);
		lst = lst->next;
	}
}

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

static void	cycle_sort(t_list **stack_a, t_list **stack_b, size_t i)
{
	if (stack_b && *stack_b && ft_cycle_lstsize(*stack_b) >= 2
		&& *(*stack_b)->sort % 2 == 0)
		rotate_rotate(stack_a, stack_b);
	else if (ft_cycle_lstsize(*stack_a) / 2 < i)
		reverse_rotate_a(stack_a);
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
	size_t	i;
	size_t	j;
	size_t	large;

	large = 20;
	i = 1;
	j = 1;
	while (ft_cycle_lstsize(*stack_a) != 3)
	{
		large = sort_push_a(stack_a, stack_b, large, ac);
		if (ft_cycle_lstsize(*stack_a) != 3)
		{
			j = prev_node(*stack_a, ac - 3, large);
			i = next_node(*stack_a, ac - 3, large);
			while (*(*stack_a)->sort > large || *(*stack_a)->sort > ac-3)
			{
				if (i < j)
					cycle_sort(stack_a, stack_b, i);
				else
					reverse_rotate_a(stack_a);
			}
		}
	}
	sort_3(stack_a);
	comp_sort(stack_a, stack_b, ac-3, ac);
}