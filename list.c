/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:52:01 by rohta             #+#    #+#             */
/*   Updated: 2024/11/15 17:34:29 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	node->num = c_num;
	node->sort = c_sort;
	node->next = node;
	return (node);
}

//void	free_cycle_list(s_list *lst)
//{
//	s_list	*start;
//	s_list	*temp;
//
//	if (!lst)
//		return ;
//	start = lst;
//	temp = lst;
//	lst = lst->next;
//	free(temp);
//	while (lst != start)
//	{
//		temp = lst;
//		lst = lst->next;
//		free(temp);
//	}
//}

//void	ft_cycle_lstadd_front(s_list **lst, s_list *new_node)
//{
//	s_list	*last;
//
//	if (!lst || !new_node)
//		return ;
//	if (!*lst)
//	{
//		*lst = new_node;
//		return ;
//	}
//	last = ft_lstlast(*lst);
//	new_node->next = *lst;
//	last->next = new_node;
//	*lst = new_node;
//}

