/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:30:54 by dcolera-          #+#    #+#             */
/*   Updated: 2023/10/24 18:05:45 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	counter(char *str, char c)
{
	int	i;
	int	ctr;

	i = 0;
	ctr = 0;
	if (ft_strncmp(str, "", 1) == 0)
		return (0);
	while (str[i] == c)
		i++;
	if (str[i] == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i + 1] == c)
				i++;
			if (str[i + 1] != 0)
				ctr++;
		}
		i++;
	}
	return (ctr + 1);
}

void	*free_mem(char **table)
{
	int	i;

	i = -1;
	while (table[++i])
		free(table[i]);
	free(table);
	return (NULL);
}

int	getminmax(char *s, char c, int ismax)
{
	int	i;

	if (ismax)
	{
		if (ft_strlen(s) == 0)
			return (0);
		i = ft_strlen(s) - 1;
		while (s[i] == c)
			i--;
		return (i + 1);
	}
	else
	{
		i = 0;
		while (s[i] == c)
			i++;
		return (i - 1);
	}
}

char	**fill_table(char **table, char *s, char c)
{
	int	vars[3];

	vars[1] = 0;
	vars[2] = 0;
	vars[0] = getminmax(s, c, 0);
	while (++vars[0] < getminmax(s, c, 1))
	{
		if (s[vars[0]] == c)
		{
			table[vars[2]] = ft_substr(s, vars[0] - vars[1], vars[1]);
			if (!table[vars[2]])
				return (free_mem(table));
			vars[2]++;
			vars[1] = 0;
			while (s[vars[0] + 1] == c)
				vars[0]++;
		}
		else
			vars[1]++;
	}
	table[vars[2]] = ft_substr(s, vars[0] - vars[1], vars[1]);
	if (!table[vars[2]])
		return (free_mem(table));
	table[vars[2] + 1] = NULL;
	return (table);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	int		x_size;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	x_size = counter(str, c) + 1;
	table = (char **)ft_calloc(x_size, sizeof(char *));
	if (!table)
		return (NULL);
	if (x_size == 1)
	{
		table[0] = NULL;
		return (table);
	}
	return (fill_table(table, (char *)str, c));
	return (table);
}
