/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_cheak.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:48:37 by rohta             #+#    #+#             */
/*   Updated: 2025/04/08 15:53:43 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cycle_listb(t_list *lst)
{
	t_list	*first;
	t_list	*tmp;

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

void	print_cycle_lista(t_list *lst)
{
	t_list	*first;
	t_list	*tmp;

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
