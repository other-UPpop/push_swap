/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_cheak.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:48:37 by rohta             #+#    #+#             */
/*   Updated: 2024/11/18 19:03:38 by rohta            ###   ########.fr       */
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

void	print_cycle_listb(s_list *lst)
{
	s_list	*first;
	s_list	*tmp;

	if (!lst)
		return ;
	first = lst;
	printf("num:%d\n", *lst->num);
//	printf("sortB:%ld\n", *lst->sort);
	lst = lst->next;
	while (lst != first)
	{
		tmp = lst;
		printf("num:%d\n", *tmp->num);
//		printf("sortB:%ld\n", *tmp->sort);
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
	printf("numberA:%d\n", *lst->num);
	printf("sortA:%ld\n", *lst->sort);
	lst = lst->next;
	while (lst != first)
	{
		tmp = lst;
		printf("numberA:%d\n", *tmp->num);
		printf("sortA:%ld\n", *tmp->sort);
		lst = lst->next;
	}
}

size_t	ft_compare(char **str, size_t i)
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
	printf("%d", argc - 1);
	stack_b = NULL;
	str = check_all_arg(argc, argv);
	stack_a = put_first_stack(str);
	//stack_b = ft_cycle_lstnew(NULL, NULL);
	print_cycle_lista(stack_a);
//	delete_top_node(&stack_a);
	//ft_cycle_lstdelone(stack_a, del_node);
//	free_cycle_list(stack_a);
//	push_a(&stack_a, &stack_b);
//	push_a(&stack_a, &stack_b);
//	push_a(&stack_a, &stack_b);
//	print_cycle_listb(stack_b);
//	push_b(&stack_a, &stack_b);
//	push_b(&stack_a, &stack_b);
//	push_b(&stack_a, &stack_b);
//	swap_a(&stack_a);
//	rotate_a(&stack_a);
//	reverse_rotate_a(&stack_a);
//	delete_end_node(&stack_a);
	if ((argc - 1) == 2)
		sort_2(&stack_a);
	if ((argc - 1) == 3)
		sort_3(&stack_a);
	if ((argc - 1) == 4)
		sort_4(&stack_a, &stack_b);
//	reverse_rotate_a(&stack_a);
//	swap_a(&stack_a);
//	size_t i = 0;
//	i = ft_cycle_lstsize(stack_a);
//	printf("%ld\n", i);
	print_cycle_listb(stack_a);
	printf("mid_command\n");
	free_str_mem(str);
	free_cycle_list(stack_a);
//	free_cycle_list(stack_b);
	return (0);
}
