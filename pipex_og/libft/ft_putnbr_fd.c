/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:11:23 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/03/15 23:26:44 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

static void	ft_putnbr_fd_real(int n, int fd)
{
	if (n / 10 == 0)
		ft_putchar_fd(n % 10 + '0', fd);
	else
	{
		ft_putnbr_fd_real(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd_real(-n, fd);
	}
	else
		ft_putnbr_fd_real(n, fd);
}
