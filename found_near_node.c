/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_near_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:12:44 by rohta             #+#    #+#             */
/*   Updated: 2024/11/20 22:34:29 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	prev_node(t_list *node_p, size_t ac, size_t large)
{
	size_t	j;

	j = 0;
	while (large < *node_p->sort || *node_p->sort > ac)
	{
		node_p = node_p->prev;
		j++;
		if (ft_cycle_lstsize(node_p) < j)
			return (0);
	}
	return (j);
}

size_t	next_node(t_list *node_n, size_t ac, size_t large)
{
	size_t	i;

	i = 0;
	while (large < *node_n->sort || *node_n->sort > ac)
	{
		node_n = node_n->next;
		i++;
		if (ft_cycle_lstsize(node_n) < i)
			return (0);
	}
	return (i);
}
