/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:32:56 by rohta             #+#    #+#             */
/*   Updated: 2024/12/14 22:31:05 by rohta            ###   ########.fr       */
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
		{
			free_cycle_list(a_list);
			free_cycle_list(new_node);
			return (NULL);
		}
		ft_cycle_lstadd_back(&a_list, new_node);
		i++;
	}
	return (a_list);
}

static void	sort_select(t_list **stack_a, t_list **stack_b, size_t ac)
{
	if ((ac - 1) == 2)
		sort_2(stack_a);
	if ((ac - 1) == 3)
		sort_3(stack_a);
	if ((ac - 1) == 4)
		sort_4(stack_a, stack_b);
	if ((ac - 1) == 5)
		sort_5(stack_a, stack_b);
	if ((ac - 1) == 6)
		sort_6(stack_a, stack_b);
	if ((ac - 1) > 6 && (ac - 1) <= 100)
		sort_100(stack_a, stack_b, ac - 1);
	if ((ac - 1) > 100)
		sort_500(stack_a, stack_b, ac - 1);
}

int	main(int argc, char *argv[])
{
	char	**str;
	t_list	*stack_a;
	t_list	*stack_b;

	str = NULL;
	stack_b = NULL;
	str = check_all_arg(argc, argv);
	if (!str)
		return (0);
	stack_a = put_first_stack(str);
	sort_select(&stack_a, &stack_b, (size_t)argc);
//``	print_cycle_listb(stack_a);
	free_str_mem(str);
	free_cycle_list(stack_a);
	return (0);
}
