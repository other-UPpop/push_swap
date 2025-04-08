/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:56:15 by rohta             #+#    #+#             */
/*   Updated: 2024/11/13 15:40:05 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_apply_character(int arg)
{
	char	*str;

	str = NULL;
	str = ft_calloc(2, sizeof(char));
	if (str)
	{
		if (arg)
			*str = (char)arg;
		else
			*str = '\0';
	}
	return (str);
}

char	*ft_apply_string(char *arg)
{
	char	*str;

	if (!arg)
		return (ft_strdup("(null)"));
	else
		str = ft_strdup(arg);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_apply_pointer(size_t arg)
{
	char	*str;

	if (!arg)
		return (ft_strdup("(nil)"));
	str = ft_apply_hex(arg, 16, LOW_HEX);
	if (!str)
		return (NULL);
	return (str);
}
