/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:37:55 by dcolera-          #+#    #+#             */
/*   Updated: 2023/09/26 05:25:34 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	int		total;

	total = count * size;
	p = (char *)malloc(total);
	if (!p)
		return (NULL);
	while (total--)
		p[total] = 0;
	return (p);
}
