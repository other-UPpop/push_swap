/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_cheak.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:48:37 by rohta             #+#    #+#             */
/*   Updated: 2024/11/15 18:01:44 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	free_str_mem(char **str)
//{
//	size_t	i;
//
//	i = 0;
//	if (str)
//	{
//		while (str[i])
//		{
//			free(str[i]);
//			i++;
//		}
//		free(str);
//	}
//}
//
//s_list	*ft_cycle_lstlast(s_list *lst)
//{
//	s_list	*last;
//
//	last = lst;
//	if (!lst)
//		return (NULL);
//	while (last->next != lst)
//		last = last->next;
//	return (last);
//}
//
//void	ft_cycle_lstadd_back(s_list **lst, s_list *new_node)
//{
//	s_list	*last;
//
//	if (!lst || !new_node)
//		return ;
//	if (!*lst)
//		*lst = new_node;
//	else
//	{
//		last = ft_cycle_lstlast(*lst);
//		last->next = new_node;
//		new_node->next = *lst;
//	}
//}
//
//s_list	*ft_cycle_lstnew(int c_num, size_t c_sort)
//{
//	s_list	*node;
//
//	node = (s_list *)malloc(sizeof(s_list));
//	if (!node)
//		return (NULL);
//	node->num = c_num;
//	node->sort = c_sort;
//	node->next = node;
//	return (node);
//}
//
//void	free_cycle_list(s_list *lst)
//{
//	s_list	*start;
//	s_list	*temp;
//
//	if (!lst)
//		return ;
//	start = lst;
//	temp = lst;
//	lst = lst->next;
//	free(temp);
//	while (lst != start)
//	{
//		temp = lst;
//		lst = lst->next;
//		free(temp);
//	}
//}
//
void	print_cycle_list(s_list *lst)
{
	s_list	*first;
	s_list	*tmp;

	if (!lst)
		return ;
	first = lst;
	printf("number:%d\n", lst->num);
	printf("sort:%ld\n", lst->sort);
	lst = lst->next;
	while (lst != first)
	{
		tmp = lst;
		printf("number:%d\n", tmp->num);
		printf("sort:%ld\n", tmp->sort);
		lst = lst->next;
	}
}

size_t	ft_compare(char **str, size_t i)
{
	size_t	j;
	size_t	x;

	j = 0;
	x = 0;
	while (str[j])
	{
		if (ft_atoi(str[i]) > ft_atoi(str[j]))
			x++;
		j++;
	}
	return (x);
}

s_list	*put_first_stack(char **str)
{
	size_t	i;
	size_t	x;
	s_list	*a_list;
	s_list	*new_node;

	i = 0;
	x = 0;
	if (!str)
		return (NULL);
	new_node = NULL;
	a_list = NULL;
	while (str[i])
	{
		x = 0;
		x = ft_compare(str, i);
		new_node = ft_cycle_lstnew(atoi(str[i]), x);
		if (!new_node)
		{
			free_cycle_list(a_list);
			return (NULL);
		}
		ft_cycle_lstadd_back(&a_list, new_node);
		i++;
	}
	return (a_list);
}

int	main(int argc, char *argv[])
{
	char	**str;
	s_list	*stack_a;
	s_list	*stack_b;

	str = NULL;
	str = check_all_arg(argc, argv);
	stack_a = put_first_stack(str);
	//stack_b = ft_cycle_lstnew(NULL, NULL);
	print_cycle_list(stack_a);
	//sort_command(stack_a, stack_b);
	free_str_mem(str);
	free_cycle_list(stack_a);
	return (0);
}
