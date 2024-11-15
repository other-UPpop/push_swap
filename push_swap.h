/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:27:54 by rohta             #+#    #+#             */
/*   Updated: 2024/11/15 17:58:58 by rohta            ###   ########.fr       */
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
	int				num;
	size_t			sort;
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

#endif
