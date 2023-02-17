/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:40:34 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/01/20 12:29:40 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_fork_last(int argc, char *argv[], t_data *d);

void	ft_fork(int argc, char *argv[], char *envp[], t_data *d)
{
	if (d->i == 2 && d->p_fff)
		exit(1);
	if (!d->path)
	{
		perror("access: cmd");
		if (d->i == argc - 2)
			ft_fork_last(argc, argv, d);
		exit(1);
	}
	if (d->i == argc - 2)
		ft_fork_last(argc, argv, d);
	else
	{	
		if (dup2(d->pip[1], STDOUT_FILENO) == -1)
			ft_exit(*d, "dup2: fork");
	}
	if (execve(d->path, d->args, envp) == -1)
		ft_exit(*d, "execve");
}

static void	ft_fork_last(int argc, char *argv[], t_data *d)
{
	int	flag;

	flag = O_WRONLY | O_CREAT;
	if (d->p_hd)
		flag = flag | O_APPEND;
	else
		flag = flag | O_TRUNC;
	d->fd = open(argv[argc - 1], flag,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (d->fd == -1)
		ft_exit(*d, "open: last fork");
	if (dup2(d->fd, STDOUT_FILENO) == -1)
		ft_exit(*d, "dup2: last fork");
	if (close(d->fd) == -1)
		ft_exit(*d, "close: last fork");
}
