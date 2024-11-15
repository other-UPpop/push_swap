/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:30:30 by rohta             #+#    #+#             */
/*   Updated: 2024/11/15 20:23:34 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(s_list **stack_a, s_list **stack_b)
{
	int	tmp_num;
	size_t	tmp_sort;
	s_list	*node_b;

	if (!stack_a || !*stack_a)
		return ;
	tmp_num = (*stack_a)->num;
	tmp_sort = (*stack_a)->sort;
	printf("%d\n", tmp_num);
//	ft_cycle_lstdelone(*stack_a, del_node);
	ft_cycle_lstdelone(*stack_a);
	*stack_a = (*stack_a)->next;
	node_b = NULL;
	node_b = ft_cycle_lstnew(tmp_num, tmp_sort);
	if (!stack_b)
		return ;
	else
		ft_cycle_lstadd_front(stack_b, node_b);
}
