/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:09:32 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:09:32 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*element;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		element = ft_lstnew((*f)(lst->content));
		if (!element)
		{
			ft_lstclear(&element, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_list, element);
		lst = lst->next;
	}
	return (new_list);
}
