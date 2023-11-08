/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:31:54 by dcolera-          #+#    #+#             */
/*   Updated: 2023/10/24 19:45:08 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	contains(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		total_length;
	char	*str;
	int		i;
	int		len_s1;

	i = -1;
	len_s1 = ft_strlen(s1);
	total_length = len_s1 + ft_strlen(s2) + 1;
	str = (char *)malloc(total_length);
	if (!str)
		return (free(s1), NULL);
	while (++i < total_length)
	{
		if (i < len_s1)
			str[i] = s1[i];
		else
			str[i] = s2[i - len_s1];
	}
	str[i - 1] = 0;
	free(s1);
	return (str);
}
