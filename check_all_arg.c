/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:36:23 by rohta             #+#    #+#             */
/*   Updated: 2024/11/15 17:13:26 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "libft/libft.h"

static char	*set_arg(int argc, char *argv[])
{
	size_t	i;
	size_t	tmp;
	size_t	len;
	char	*sp_str;

	i = 1;
	tmp = 0;
	len = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
		{
			printf("Error");
			return (0);
		}
		tmp = ft_strlen(argv[i]);
		len += tmp + 2;
		i++;
	}
	sp_str = NULL;
	sp_str = (char *)malloc(len + 1);
	if (!sp_str)
		return (NULL);
	return (sp_str);
}

static char	*get_arg(int argc, char *argv[], char *sp_str)
{
	size_t	i;
	size_t	len;
	size_t	tmp;
	char	*str;

	i = 1;
	tmp = 0;
	str = NULL;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		str = (char *)malloc(len + 1);
		if (!str)
			return (NULL);
		ft_strlcpy(str, " ", 2);
		ft_strlcat(str, argv[i], len + 2);
		ft_strlcat(str, " ", len + 2);
		tmp += len + 2;
		ft_strlcat(sp_str, str, (tmp + len));
		i++;
		free(str);
	}
	return (sp_str);
}

char	**div_arg(char *set_str)
{
	char	**aft_str;

	aft_str = NULL;
	if (set_str)
		aft_str = ft_split(set_str, ' ');
	free(set_str);
	return (aft_str);
}

static char	**get_arg_check(int argc, char *argv[])
{
	void	*sp_str;
	void	*set_str;
	char	**aft_str;

	if (argc < 2)
		return (NULL);
	sp_str = set_arg(argc, argv);
	if (!sp_str)
		return (NULL);
	set_str = get_arg(argc, argv, sp_str);
	if (!set_str)
	{
		free(sp_str);
		return (NULL);
	}
	aft_str = div_arg(set_str);
	if (!aft_str)
	{
		free(set_str);
		return (NULL);
	}
	if ((ck_over(aft_str) || ck_dig(aft_str) || ck_dup(aft_str)) == 1)
		return (NULL);
	return (aft_str);
}

char	**check_all_arg(int argc, char *argv[])
{
	int		i;
	char	**str;

	i = 0;
	str = get_arg_check(argc, argv);
	if (!str)
		return (0);
	return (str);
}
