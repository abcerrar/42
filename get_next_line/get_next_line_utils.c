/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:31:54 by dcolera-          #+#    #+#             */
/*   Updated: 2023/10/10 01:11:17 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	size_t	total_length;
	char	*str;
	size_t	i;

	i = -1;
	total_length = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(total_length);
	if (!str)
		return (NULL);
	while (++i < total_length)
	{
		if (i < ft_strlen(s1))
			str[i] = s1[i];
		else
			str[i] = s2[i - ft_strlen(s1)];
	}
	str[i - 1] = 0;
	free(s1);
//	free(s2);
	return (str);
}
