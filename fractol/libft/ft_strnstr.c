/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:33:32 by dcolera-          #+#    #+#             */
/*   Updated: 2023/10/24 18:23:13 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str && len == 0)
		return (NULL);
	if (!*needle || !needle)
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (needle[j] == str[i] && i < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)str + (i - j));
			j++;
			i++;
		}
		i = i - j;
		i++;
	}
	return (NULL);
}
