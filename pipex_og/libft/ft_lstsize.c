/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:45:48 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/03/17 11:50:36 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*l;

	if (lst == NULL)
		return (0);
	size = 1;
	l = lst;
	while (l->next != NULL)
	{
		size++;
		l = l->next;
	}
	return (size);
}
