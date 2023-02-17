/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:10:36 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/03/13 22:19:48 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	nbs_to_add;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	if (size > len_dst)
	{
		i = 0;
		nbs_to_add = size - len_dst - 1;
		while (nbs_to_add && src[i])
		{
			dst[len_dst + i] = src[i];
			i++;
			nbs_to_add--;
		}
		if (i < size)
			dst[len_dst + i] = '\0';
		return (len_dst + len_src);
	}
	return (size + len_src);
}
