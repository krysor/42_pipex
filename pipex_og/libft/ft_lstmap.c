/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:44:33 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/03/17 16:09:40 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*nxt;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (new == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		nxt = ft_lstnew(f(lst->content));
		if (nxt == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, nxt);
		lst = lst->next;
	}
	return (new);
}
