/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:57:00 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/03/16 18:56:27 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_zerosubst(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			str[i] = '\0';
		i++;
	}
	return (str);
}

static int	ft_strnb(char const *s, char c)
{
	int	p;
	int	nb;

	p = 0;
	nb = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (p == 0)
			{
				nb++;
				p = 1;
			}
		}
		else
			p = 0;
		s++;
	}
	return (nb);
}

static char	**ft_arrstr(char **arr, char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[i] != '\0')
		{
			arr[j] = ft_strdup(str + i);
			if (arr[j] == NULL)
			{
				while (j >= 0)
					free(arr[j--]);
				return (NULL);
			}
			i += ft_strlen(arr[j]);
			j++;
		}
		else
			i++;
	}
	arr[j] = 0;
	free(str);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*str;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	str = ft_zerosubst(str, c);
	arr = (char **)malloc(sizeof(char *) * (ft_strnb(s, c) + 1));
	if (arr == NULL)
	{
		free(str);
		return (NULL);
	}
	arr = ft_arrstr(arr, str, len);
	if (arr == NULL)
	{
		free(str);
		free(arr);
		return (NULL);
	}
	return (arr);
}
