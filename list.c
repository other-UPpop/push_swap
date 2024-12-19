/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:52:01 by rohta             #+#    #+#             */
/*   Updated: 2024/12/19 17:13:49 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_cycle_lstsize(t_list *lst)
{
	t_list	*last;
	size_t	i;

	last = lst;
	i = 1;
	if (!lst)
		return (0);
	while (last->next != lst && last->next)
	{
		if (!last->next)
			return (0);
		last = last->next;
		i++;
	}
	return (i);
}

t_list	*ft_cycle_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (!lst)
		return (NULL);
	while (last->next != lst)
		last = last->next;
	return (last);
}

void	ft_cycle_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		last = ft_cycle_lstlast(*lst);
		last->next = new_node;
		(*lst)->prev = new_node;
		new_node->prev = last;
		new_node->next = *lst;
	}
}

t_list	*ft_cycle_lstnew(int num, size_t sort)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->num = malloc(sizeof(int));
	if (!node->num)
	{
		free(node);
		return (NULL);
	}
	node->sort = malloc(sizeof(size_t));
	if (!node->sort)
	{
		free(node->num);
		free(node);
		return (NULL);
	}
	*(node->num) = num;
	*(node->sort) = sort;
	node->next = node;
	node->prev = node;
	return (node);
}

// t_list	*ft_cycle_lstnew(int c_num, size_t c_sort)
//{
//	t_list	*node;
//
//	node = (t_list *)malloc(sizeof(t_list));
//	if (!node)
//		return (NULL);
//	node->num = (int *)malloc(sizeof(int));
//	node->sort = (size_t *)malloc(sizeof(size_t));
//	if (!node->num || !node->sort)
//	{
//		solo_node_del(node);
//		return (NULL);
//	}
//	*node->num = c_num;
//	*node->sort = c_sort;
//	node->next = node;
//	node->prev = node;
//	return (node);
//}

void	ft_cycle_lstadd_front(t_list **lst, t_list *new_node)
{
	t_list	*last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
		*lst = new_node;
	else
	{
		last = ft_cycle_lstlast(*lst);
		new_node->next = *lst;
		new_node->prev = last;
		last->next = new_node;
		(*lst)->prev = new_node;
		*lst = new_node;
	}
}
