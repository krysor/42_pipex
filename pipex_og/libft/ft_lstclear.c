/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:44:33 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/03/17 13:26:58 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{	
	t_list	*l;

	if (lst == NULL || del == NULL)
		return ;
	l = *lst;
	while (l != NULL)
	{
		l = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = l;
	}
	lst = NULL;
}
