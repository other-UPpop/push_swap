/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:43:33 by rohta             #+#    #+#             */
/*   Updated: 2024/11/15 18:02:51 by rohta            ###   ########.fr       */
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
