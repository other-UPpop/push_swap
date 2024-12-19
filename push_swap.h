/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:27:54 by rohta             #+#    #+#             */
/*   Updated: 2024/12/19 17:56:05 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct p_list
{
	int				*num;
	size_t			*sort;
	struct p_list	*next;
	struct p_list	*prev;
}					t_list;

int					ck_over(char **aft_str);
int					ck_dig(char **aft_str);
int					ck_dup(char **aft_str);

char				**check_all_arg(int argc, char *argv[]);

size_t				ft_cycle_lstsize(t_list *lst);
size_t				prev_node(t_list *node_p, size_t ac, size_t large);
size_t				next_node(t_list *node_n, size_t ac, size_t large);

t_list				*ft_cycle_lstlast(t_list *lst);
t_list				*ft_cycle_lstnew(int c_num, size_t c_sort);

void				ft_cycle_lstadd_back(t_list **lst, t_list *new_node);
void				free_cycle_list(t_list *lst);
void				free_str_mem(char **str);
void				push_a(t_list **stack_a, t_list **stack_b);
void				push_b(t_list **stack_a, t_list **stack_b);
void				swap_a(t_list **stack_a);
void				swap_b(t_list **stack_b);
void				swap_swap(t_list **stack_a, t_list **stack_b);
void				rotate_a(t_list **stack_a);
void				rotate_b(t_list **stack_b);
void				rotate_rotate(t_list **stack_a, t_list **stack_b);
void				reverse_rotate_a(t_list **stack_a);
void				reverse_rotate_b(t_list **stack_b);
void				reverse_rotate_rotate(t_list **stack_a, t_list **stack_b);
void				ft_cycle_lstadd_front(t_list **lst, t_list *new_node);
void				solo_node_del(t_list *node);
void				delete_top_node(t_list **stack);
void				delete_end_node(t_list **stack);
void				ft_cycle_lstdelone(t_list *lst,
						void (*del)(int *, size_t *));
void				del_node(int *num, size_t *sort);
void				sort_2(t_list **stack_a);
void				reverse_sort_2(t_list **stack_b);
void				sort_3(t_list **stack_a);
void				reverse_sort_3(t_list **stack_b);
void				sort_4(t_list **stack_a, t_list **stack_b);
void				sort_5(t_list **stack_a, t_list **stack_b);
void				sort_6(t_list **stack_a, t_list **stack_b);
void				sort_100(t_list **stack_a, t_list **stack_b, size_t ac);
void				sort_500(t_list **stack_a, t_list **stack_b, size_t ac);

#endif
