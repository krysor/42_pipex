/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:34:20 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/01/20 12:29:08 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_hd_loop(t_data *d);

void	ft_heredoc(t_data *d, char *argv[])
{
	d->p_hd = 1;
	d->l = ft_strlen(argv[2]);
	d->fd = open(d->tmp, O_WRONLY | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (d->fd == -1)
		perror("open: temp: first");
	d->s = get_next_line(0);
	while (d->s && (ft_strncmp(d->s, argv[2], d->l)
			|| d->l != (int)ft_strlen(d->s) - 1))
		ft_hd_loop(d);
	if (d->s)
		free(d->s);
	if (close(d->fd) == -1)
		perror("close: temp: first");
	d->i = 3;
	d->fd = open(d->tmp, O_RDONLY);
	if (d->fd == -1)
		perror("open: temp: second");
	if (dup2(d->fd, STDIN_FILENO) == 1)
		perror("dup2: here_doc");
	if (close(d->fd) == -1)
		perror("close: temp: second");
	if (unlink(d->tmp) == -1)
		perror("unlink");
}

static void	ft_hd_loop(t_data *d)
{
	if (write(d->fd, d->s, ft_strlen(d->s)) == -1)
		perror("write: temp");
	free(d->s);
	d->s = get_next_line(0);
}
