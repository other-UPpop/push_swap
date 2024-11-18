/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:43:33 by rohta             #+#    #+#             */
/*   Updated: 2024/11/18 19:02:42 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	del_node(int *num, size_t *sort)
//{
//	if (num)
//		free(num);
//	if (sort)
//		free(sort);
//}

void	del_node(int *num, size_t *sort)
{
	if (num)
		free(num);
	if (sort)
		free(sort);
}

void	ft_cycle_lstdelone(s_list *lst, void (*del)(int *, size_t *))
{
	if (!lst)
		return ;
	del(lst->num, lst->sort);
	free(lst);
}

void	solo_node_del(s_list *stack, s_list *node)
{
	ft_cycle_lstdelone(node, del_node);
	stack = NULL;
	return ;
}

void	delete_top_node(s_list **stack)
{
	s_list	*node;
	s_list	*last_node;

	if (!stack || !*stack)
		return ;
	node = *stack;
	if (node->next == *stack)
		return (solo_node_del(*stack, node));
	last_node = *stack;
	last_node = ft_cycle_lstlast(*stack);
	*stack = node->next;
	last_node->next = *stack;
	ft_cycle_lstdelone(node, del_node);
}

void	delete_end_node(s_list **stack)
{
	s_list	*node;
	s_list	*next_last_node;
	s_list	*last_node;

	if (!stack || !*stack)
		return ;
	node = *stack;
	if ((*stack)->next == *stack)
		return (solo_node_del(*stack, node));
	last_node = *stack;
	next_last_node = *stack;
	last_node = ft_cycle_lstlast(*stack);
	while (next_last_node->next != last_node)
		next_last_node = next_last_node->next;
	next_last_node->next = *stack;
	ft_cycle_lstdelone(last_node, del_node);
}

void	free_str_mem(char **str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	free_cycle_list(s_list *lst)
{
	s_list	*start;
	s_list	*temp;

	if (!lst)
		return ;
	start = lst;
	temp = lst;
	lst = lst->next;
	free(temp);
	while (lst != start)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}
