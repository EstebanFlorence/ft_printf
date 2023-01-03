/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:02:27 by adi-nata          #+#    #+#             */
/*   Updated: 2022/11/02 23:18:17 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*novalist;
	t_list	*novonodo;

	if (!f || !del)
		return (NULL);
	novalist = NULL;
	while (lst)
	{
		novonodo = ft_lstnew(f(lst->content));
		if (novonodo == NULL)
		{
			ft_lstclear(&novalist, del);
			return (NULL);
		}
		ft_lstadd_back(&novalist, novonodo);
		lst = lst->next;
	}
	return (novalist);
}
