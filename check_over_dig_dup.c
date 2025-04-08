/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_over_dig_dup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:43:00 by rohta             #+#    #+#             */
/*   Updated: 2025/04/08 22:29:40 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ck_over(char **aft_str)
{
	size_t	i;
	long	num;

	i = 0;
	while (aft_str[i] != NULL)
	{
		num = ft_long_atoi(aft_str[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_printf("Error\n");
			free_str_mem(aft_str);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ck_dig(char **aft_str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (aft_str[i])
	{
		j = 0;
		if (aft_str[i][0] == '-')
			j++;
		while (aft_str[i][j])
		{
			if (!ft_isdigit(aft_str[i][j]))
			{
				ft_printf("Error\n");
				free_str_mem(aft_str);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ck_dup(char **aft_str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (aft_str[i] != NULL)
	{
		j = i + 1;
		while (aft_str[j] != NULL)
		{
			if (ft_atoi(aft_str[i]) == ft_atoi(aft_str[j]))
			{
				ft_printf("Error\n");
				free_str_mem(aft_str);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_sort(t_list *lst)
{
	t_list	*first;
	t_list	*tmp;

	if (!lst)
		return (0);
	first = lst;
	if (*(lst->num) > *(lst->next->num))
		return (1);
	lst = lst->next;
	while (lst->next != first)
	{
		tmp = lst;
		if (*(tmp->num) > *(tmp->next->num))
			return (1);
		lst = lst->next;
	}
	return (0);
}
