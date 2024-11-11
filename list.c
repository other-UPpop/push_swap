/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:52:01 by rohta             #+#    #+#             */
/*   Updated: 2024/11/11 17:03:57 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

s_list	*ft_cycle_lestnew(void *content)
{
	s_list	*node;

	node =  (s_list *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node -> content = cntent;
	node -> next = NULL;
	return (node);
}

void	ft_cycle_lstadd_front(s_list **lst, s_list *new_node)
{
	if (!lst || !new_node)
		return ;
	new_node -> next = *lst;
	*lst = new_node;
}
