/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:14:32 by dcolera-          #+#    #+#             */
/*   Updated: 2023/10/24 18:01:51 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_length;
	char	*str;
	size_t	i;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	if (!s1 || !s2)
		return (NULL);
	i = -1;
	total_length = len_s1 + ft_strlen(s2) + 1;
	str = (char *)malloc(total_length);
	if (!str)
		return (NULL);
	while (++i < total_length)
	{
		if (i < len_s1)
			str[i] = s1[i];
		else
			str[i] = s2[i - len_s1];
	}
	return (str);
}
