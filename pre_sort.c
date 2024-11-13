/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:52:41 by rohta             #+#    #+#             */
/*   Updated: 2024/11/12 17:37:54 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

void	pre_comp(char **str)
{
	size_t	i;
	size_t	j;
	size_t	x;
//	s_list	**a_list;	

	i = 0;
	j = 0;
	x = 0;
	if (!str)
		return ;
	while (str[i])
	{
		x = 0;
		j = 0;
		while (str[j])
		{
			if (str[i] > str[j])
			x++;
			i++;
		}
		printf("x:%ld [%d]\n", x, atoi(str[i]));
		//a_list = ft_cycle_lstnew(atoi(str[i]), x);
		//ft_cycle_lstadd_back(a_list);
		i++;
	}
}
