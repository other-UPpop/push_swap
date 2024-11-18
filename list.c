/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:52:01 by rohta             #+#    #+#             */
/*   Updated: 2024/11/18 17:15:32 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_cycle_lstsize(s_list *lst)
{
	s_list	*last;
	size_t	i;

	last = lst;
	i = 1;
	if (!lst)
		return (0);
	while (last->next != lst)
	{
		last = last->next;
		i++;
	}
	return (i);
}

s_list	*ft_cycle_lstlast(s_list *lst)
{
	s_list	*last;

	last = lst;
	if (!lst)
		return (NULL);
	while (last->next != lst)
		last = last->next;
	return (last);
}

void	ft_cycle_lstadd_back(s_list **lst, s_list *new_node)
{
	s_list	*last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
		*lst = new_node;
	else
	{
		last = ft_cycle_lstlast(*lst);
		last->next = new_node;
		new_node->next = *lst;
	}
}

s_list	*ft_cycle_lstnew(int c_num, size_t c_sort)
{
	s_list	*node;

	node = (s_list *)malloc(sizeof(s_list));
	if (!node)
		return (NULL);
	node->num = (int *)malloc(sizeof(int));
	node->sort = (size_t *)malloc(sizeof(size_t));
	if (!node->num || !node->sort)
		return (NULL);
	*node->num = c_num;
	*node->sort = c_sort;
	node->next = node;
	return (node);
}

//void	del_node(int *num, size_t *sort)
//{
//	free(num);
//	free(sort);
//}
//
//void	ft_cycle_lstdelone(s_list *lst, void (*del)(int *, size_t *))
//{
//	if (!lst || !del)
//		return ;
//	del(lst->num ,lst->sort);
//	free(lst);
//}
//

void	ft_cycle_lstadd_front(s_list **lst, s_list *new_node)
{
	s_list	*last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		new_node->next = new_node;
	}
	else
	{
		last = ft_cycle_lstlast(*lst);
		new_node->next = *lst;
		last->next = new_node;
		*lst = new_node;
	}
}
