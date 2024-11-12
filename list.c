/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:52:01 by rohta             #+#    #+#             */
/*   Updated: 2024/11/12 16:33:36 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

s_list	*ft_cycle_lestnew(void *content)
{
	s_list	*node;

	node =  (s_list *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->size = 0;
	node->sort = 0;
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
	new_node -> next = *lst;
	*lst = new_node;
	last = ft_lstlast(*lst);
	last->next = *lst;
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
	last->next = first;
}


