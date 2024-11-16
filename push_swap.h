/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:27:54 by rohta             #+#    #+#             */
/*   Updated: 2024/11/16 19:45:21 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <string.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct c_list
{
	int				*num;
	size_t			*sort;
	struct c_list	*next;
}					s_list;

char	**check_all_arg(int argc, char *argv[]);
int		ck_over(char **aft_str);
int		ck_dig(char **aft_str);
int		ck_dup(char **aft_str);
s_list	*ft_cycle_lstlast(s_list *lst);
void	ft_cycle_lstadd_back(s_list **lst, s_list *new_node);
s_list	*ft_cycle_lstnew(int c_num, size_t c_sort);
void	free_cycle_list(s_list *lst);
void	free_str_mem(char **str);
//void	ft_cycle_lstdelone(s_list *lst);:wq
void	ft_cycle_lstdelone(s_list *lst, void (*del)(int *, size_t *));
void	del_node(int *num, size_t *sort);
void	push_a(s_list **stack_a, s_list **stack_b);
void	push_b(s_list **stack_a, s_list **stack_b);
void	swap_a(s_list **stack_a);
void	rotate_a(s_list **stack_a);
void	reverse_rotate_a(s_list **stack_a);
void	ft_cycle_lstadd_front(s_list **lst, s_list *new_node);
void	delete_top_node(s_list **stack);
void	delete_end_node(s_list **stack);

#endif
