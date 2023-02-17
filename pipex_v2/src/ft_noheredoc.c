/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noheredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:29:54 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/01/20 11:18:32 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_noheredoc(t_data *d, char *argv[])
{
	char	*s;

	d->p_fff = 0;
	s = "tmptaX3IYCp04wBqNGME2BlyMedF0PyQPWb";
	d->i = 2;
	d->fd = open(argv[1], O_RDONLY);
	if (d->fd == -1)
	{	
		perror("open: infile");
		d->p_fff = 1;
		d->fd = open(s, O_RDONLY | O_CREAT | O_TRUNC);
	}
	if (dup2(d->fd, STDIN_FILENO) == -1)
		perror("dup2: infile");
	if (close(d->fd) == -1)
		perror("close: infile");
	if (d->p_fff)
	{
		if (unlink(s) == -1)
			perror("unlink: tmp infile");
	}
}
