/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:03:35 by rohta             #+#    #+#             */
/*   Updated: 2024/11/27 18:18:59 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_cycle_list(t_list *lst)
{
	t_list	*start;
	t_list	*temp;

	if (!lst)
		return ;
	start = lst;
	while (lst != start)
	{
		temp = lst->next;
		if (temp->num)
			free(temp->num);
		if (temp->sort)
			free(temp->sort);
		lst->next = temp->next;
		free(temp);
	}
	free(lst);
}
