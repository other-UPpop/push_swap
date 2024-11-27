/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_cheak.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:48:37 by rohta             #+#    #+#             */
/*   Updated: 2024/11/27 16:53:17 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cycle_listb(s_list *lst)
{
	s_list	*first;
	s_list	*tmp;

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

void	print_cycle_lista(s_list *lst)
{
	s_list	*first;
	s_list	*tmp;

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
