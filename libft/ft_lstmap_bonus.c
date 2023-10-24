/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolera- <dcolera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 23:50:21 by dcolera-          #+#    #+#             */
/*   Updated: 2023/10/24 16:08:24 by dcolera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*newlist;
	void	*new_content;

	newlist = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
			return (ft_lstclear(&newlist, del), NULL);
		aux = ft_lstnew(new_content);
		if (!aux)
		{
			del(new_content);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, aux);
		lst = lst -> next;
	}
	return (newlist);
}
