/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:44:12 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/01/20 11:15:00 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	d;

	if (argc != 5)
		return (1);
	d.p_hd = 0;
	ft_noheredoc(&d, argv);
	d.paths = ft_getallpaths(envp);
	if (!d.paths)
		exit(1);
	while (d.i < argc - 1)
		ft_loop(argc, argv, envp, &d);
	ft_freearr(d.paths);
	return (0);
}
