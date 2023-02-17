/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:25:20 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/03/12 23:45:52 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	prod;

	prod = nmemb * size;
	str = malloc(prod);
	if (str == NULL)
		return (NULL);
	return (ft_memset(str, 0, prod));
}
