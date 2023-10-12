/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:31:54 by dcolera-          #+#    #+#             */
/*   Updated: 2023/10/12 03:31:51 by dcolera-         ###   ########.fr       */
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
	size_t	len_s1;

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
//	free(s2);
	return (str);
}
