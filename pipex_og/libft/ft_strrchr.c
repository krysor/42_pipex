/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:57:39 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/03/16 14:56:24 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (((unsigned char *)s)[i] == (unsigned char)c)
		return ((char *)s + i);
	i--;
	while (i >= 0 && s[i])
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
