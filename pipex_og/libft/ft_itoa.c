/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:19:27 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/03/15 19:11:48 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charnb(int n)
{
	int	nb;
	int	div;

	nb = 10;
	div = 1000000000;
	while (n / div == 0)
	{
		nb--;
		div /= 10;
	}
	return (nb);
}

static void	ft_itoareal(int n, char *str, int len)
{
	int	i;

	i = len - 1;
	while (n / 10 != 0)
	{
		str[i] = n % 10 + '0';
		i--;
		n /= 10;
	}
	str[i] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	int		nbchr;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
		nbchr = 1 + ft_charnb(-n);
	else
		nbchr = ft_charnb(n);
	str = (char *)malloc(sizeof(char) * (nbchr + 1));
	if (str == NULL)
		return (NULL);
	str[nbchr] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	ft_itoareal(n, str, nbchr);
	return (str);
}
