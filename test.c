#include "libft/libft.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "libft/libft.a"

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*space_str;
	char	*string;
	char	**aft_str;
	size_t	tmp;
	size_t	len;

	i = 1;
	j = 1;
	space_str = NULL;
	string = NULL;
	aft_str = NULL;
	tmp = 0;
	len = 0;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (strlen(argv[i]) == 0)
		{
			printf("%s", "enpty");
			return (0);
		}
		tmp = strlen(argv[i]);
		len += tmp + 2;
		++i;
	}
	space_str = (char *)malloc(len + 1);
	if (space_str == NULL)
		return (0);
	i = 1;
	while (i < argc)
	{
		string = (char *)malloc(strlen(argv[i]));
		if (i == 2)
			strcpy(string, " ");
		else
			strcat(string, " ");
		strcat(string, argv[i]);
		strcat(string, " ");
		strcat(space_str, string);
		printf("%s\n", space_str);
		++i;
	}
	printf("%s\n", space_str);
	if (space_str != NULL)
		aft_str = ft_split(space_str, ' ');
	i = 0;
	while (aft_str[i] != NULL)
	{
		printf("%s\n", aft_str[i]);
		i++;
	}
	i = 0;
	j = 0;
	while (aft_str[i] != NULL)
	{
		printf("%ld\n", ft_long_atoi(aft_str[i]));
		if (ft_long_atoi(aft_str[i]) >= INT_MAX
			|| ft_long_atoi(aft_str[i]) <= INT_MIN)
		{
			printf("int over");
			return (0);
		}
		while (aft_str[i][j])
		{
			if (!ft_isdigit(aft_str[i][j]))
			{
				printf("error");
				return (0);
			}
			j++;
		}
		i++;
	}
	j = 0;
	i = 0;
	while (aft_str[i] != NULL)
	{
		j = i + 1;
		while (aft_str[j] != NULL)
		{
			if (atoi(aft_str[i]) == atoi(aft_str[j]))
			{
				printf("error");
				free(aft_str);
				free(space_str);
				return (0);
				exit;
			}
			j++;
		}
		i++;
	}
	printf("true");
	free(aft_str);
	free(space_str);
	return (0);
}
