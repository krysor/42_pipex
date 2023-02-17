/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:34:51 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/01/20 12:22:33 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_loop(int argc, char *argv[], char *envp[], t_data *d)
{
	d->args = ft_split(argv[d->i], ' ');
	if (!d->args)
		ft_exit(*d, "ft_split: args");
	d->path = ft_getpath(d->args[0], d->paths);
	if (pipe(d->pip) == -1)
		ft_exit(*d, "pipe");
	d->pid = fork();
	if (d->pid == -1)
		ft_exit(*d, "fork");
	if (!(d->pid))
		ft_fork(argc, argv, envp, d);
	if (close(d->pip[1]) == -1)
		ft_exit(*d, "close: pipe write end");
	if (waitpid(d->pid, NULL, 0) == -1)
		ft_exit(*d, "waitpid");
	if (dup2(d->pip[0], STDIN_FILENO) == -1)
		ft_exit(*d, "dup2: after wait");
	ft_freearr(d->args);
	free(d->path);
	d->i++;
}
