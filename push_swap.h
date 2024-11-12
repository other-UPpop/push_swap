/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:27:54 by rohta             #+#    #+#             */
/*   Updated: 2024/11/12 15:47:13 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct c_list
{
	int	size;
	size_t	sort;
	c_list	next
}	s_list
