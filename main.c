/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:32:56 by rohta             #+#    #+#             */
/*   Updated: 2025/04/08 22:00:07 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_compare(char **str, size_t i)
{
	size_t	j;
	size_t	x;

	j = 0;
	x = 1;
	while (str[j])
	{
		if (ft_atoi(str[i]) > ft_atoi(str[j]))
			x++;
		j++;
	}
	return (x);
}

static t_list	*free_new_node(t_list *a_list, t_list *new_node)
{
	free_cycle_list(a_list);
	free_cycle_list(new_node);
	return (NULL);
}

static t_list	*put_first_stack(char **str)
{
	size_t	i;
	size_t	x;
	t_list	*a_list;
	t_list	*new_node;

	i = 0;
	x = 0;
	if (!str)
		return (NULL);
	a_list = NULL;
	while (str[i])
	{
		new_node = NULL;
		x = 0;
		x = ft_compare(str, i);
		new_node = ft_cycle_lstnew(ft_atoi(str[i]), x);
		if (!new_node)
			return (free_new_node(a_list, new_node));
		ft_cycle_lstadd_back(&a_list, new_node);
		i++;
	}
	return (a_list);
}

static void	sort_select(t_list **stack_a, t_list **stack_b, size_t ac)
{
	if (ac == 2)
		sort_2(stack_a);
	if (ac == 3)
		sort_3(stack_a);
	if (ac == 4)
		sort_4(stack_a, stack_b);
	if (ac == 5)
		sort_5(stack_a, stack_b);
	if (ac == 6)
		sort_6(stack_a, stack_b);
	if (ac > 6 && ac <= 100)
		sort_100(stack_a, stack_b, ac);
	if (ac > 100)
		sort_500(stack_a, stack_b, ac);
}

int	main(int argc, char *argv[])
{
	char	**str;
	size_t	ac;
	t_list	*stack_a;
	t_list	*stack_b;

	str = NULL;
	stack_b = NULL;
	str = check_all_arg(argc, argv);
	if (!str)
	{
		free_str_mem(str);
		return (0);
	}
	stack_a = put_first_stack(str);
	if (check_sort(stack_a) == 1)
	{
		ac = ft_cycle_lstsize(stack_a);
		sort_select(&stack_a, &stack_b, ac);
	}
	free_str_mem(str);
	free_cycle_list(stack_a);
	return (0);
}
