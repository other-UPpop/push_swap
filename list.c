/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:52:01 by rohta             #+#    #+#             */
/*   Updated: 2024/11/12 17:19:28 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_list	*ft_cycle_lstnew(int c_size, size_t c_sort)
{
	s_list	*node;

	node = (s_list *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->size = c_size;
	node->sort = c_sort;
	node->next = node;
	return (node);
}

s_list	*ft_lstlast(s_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_cycle_lstadd_front(s_list **lst, s_list *new_node)
{
	s_list	*last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = ft_lstlast(*lst);
	new_node->next = *lst;
	last->next = new_node;
	*lst = new_node;
}

void	ft_cycle_lstadd_back(s_list **lst, s_list *new_node)
{
	s_list	*last;
	s_list	*first;

	if (!lst || !new_node)
		return ;
	first = lst;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new_node;
	new_node->next = *lst;
}
