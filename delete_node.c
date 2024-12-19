/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:00:53 by rohta             #+#    #+#             */
/*   Updated: 2024/12/14 00:08:19 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_node(int *num, size_t *sort)
{
	if (num)
		free(num);
	if (sort)
		free(sort);
}

void	ft_cycle_lstdelone(t_list *lst, void (*del)(int *, size_t *))
{
	if (!lst)
		return ;
	del(lst->num, lst->sort);
	free(lst);
}

void	solo_node_del(t_list *node)
{
	if (node)
	{
		ft_cycle_lstdelone(node, del_node);
		node = NULL;
	}
}

void	delete_top_node(t_list **stack)
{
	t_list	*node;
	t_list	*last_node;

	if (!stack || !*stack)
		return ;
	node = *stack;
	last_node = ft_cycle_lstlast(*stack);
	if (node->next == *stack)
	{
		*stack = NULL;
		return (solo_node_del(node));
	}
	else
	{
		*stack = node->next;
		last_node->next = *stack;
		(*stack)->prev = last_node;
		ft_cycle_lstdelone(node, del_node);
		node = NULL;
	}
}

void	delete_end_node(t_list **stack)
{
	t_list	*node;
	t_list	*next_last_node;
	t_list	*last_node;

	if (!stack || !*stack)
		return ;
	node = *stack;
	if ((*stack)->next == *stack)
		return (solo_node_del(node));
	last_node = *stack;
	next_last_node = *stack;
	last_node = ft_cycle_lstlast(*stack);
	while (next_last_node->next != last_node)
		next_last_node = next_last_node->next;
	next_last_node->next = *stack;
	ft_cycle_lstdelone(last_node, del_node);
}
