/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:03:40 by rohta             #+#    #+#             */
/*   Updated: 2024/11/13 15:43:52 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static
ssize_t	ft_write_str(t_params *params, ssize_t print_len, ssize_t put_width)
{
	ssize_t	byte;
	ssize_t	i;
	char	c;

	byte = 0;
	i = 0;
	c = ' ';
	if (params->flags->flag_zero)
		c = '0';
	if (!ft_isprint(*params->converted) && params->specifier == 'c'
		&& *params->converted == 0)
		--put_width;
	if (!(params->flags->flag_minus) && put_width > 0)
		while (i++ < put_width)
			byte += write(STDOUT_FD, &c, sizeof(char));
	if (params->specifier == 'c' && !(ft_isprint(*params->converted)))
		byte += write(STDOUT_FD, &(*params->converted), sizeof(char));
	else
		byte += write(STDOUT_FD, params->converted, print_len);
	if (params->flags->flag_minus && put_width > 0)
		while (i++ < put_width)
			byte += write(STDOUT_FD, " ", sizeof(char));
	return (byte);
}

static ssize_t	ft_conv_str(t_params *params, ssize_t conv_len)
{
	if ((*params->precision < 6) && params->dot == true
		&& ft_strncmp(params-> converted, "(null)", 7) == 0)
		return (0);
	if (0 <= *params->precision && *params->precision <= conv_len
		&& 0 < *params->precision)
		return (*params->precision);
	if ((conv_len < *params->precision && *params->precision)
		|| *params->precision == NOT_SPEC)
		return (conv_len);
	return (0);
}

ssize_t	ft_write_string(t_params *params)
{
	ssize_t	conv_len;
	ssize_t	put_width;
	ssize_t	print_len;

	if (!params)
		return (PRINTF_NULL);
	put_width = 0;
	conv_len = ft_strlen(params->converted);
	if (params->specifier == 'c')
		*params->precision = NOT_SPEC;
	print_len = ft_conv_str(params, conv_len);
	if (print_len < *params->width && *params->width != NOT_SPEC)
		put_width = *params->width - print_len;
	else
		put_width = 0;
	return (ft_write_str(params, print_len, put_width));
}
