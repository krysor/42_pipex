/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:38:40 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/03/12 22:15:18 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ind_lst;
	char	*str;

	str = (char *)big;
	ind_lst = ft_strlen(little);
	if (ind_lst == 0)
		return (str);
	ind_lst -= 1;
	i = 0;
	while (i < len && str[i])
	{
		j = 0;
		while (i + j < len && str[i + j] == little[j])
		{
			if (j == ind_lst)
				return (str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
