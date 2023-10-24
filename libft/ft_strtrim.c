/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:00:28 by dcolera-          #+#    #+#             */
/*   Updated: 2023/10/24 18:32:15 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	contains(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim_aux(char const *s1, char const *set, int start, int end)
{
	int		i;
	char	*s;
	int		total;

	i = -1;
	if (!s1 || !set)
		return (NULL);
	while (contains((char *)set, s1[++i]) && start < (int)ft_strlen(s1) - 1)
		start++;
	i = ft_strlen(s1);
	while (contains((char *)set, s1[--i]) && end < (int)ft_strlen(s1) - 1)
		end++;
	total = start + end;
	if (total > (int)ft_strlen(s1))
		return (ft_strdup(""));
	s = (char *)malloc((int)ft_strlen(s1) - total + 1);
	if (!s)
		return (NULL);
	i = -1;
	while (start < ((int)ft_strlen(s1) - end))
		s[++i] = s1[start++];
	s[++i] = '\0';
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	return (ft_strtrim_aux(s1, set, 0, 0));
}
