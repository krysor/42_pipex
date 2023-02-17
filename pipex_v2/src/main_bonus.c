/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:44:12 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/01/20 11:15:05 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	d;

	d.hd = "here_doc";
	d.tmp = "tempZHsL5juDbhOSi5axlDant6MzTNYDcg8I";
	d.p_hd = 0;
	if (argc < 5)
		return (1);
	if (argc >= 6 && !ft_strncmp(argv[1], d.hd, ft_strlen(d.hd))
		&& ft_strlen(argv[1]) == ft_strlen(d.hd))
		ft_heredoc(&d, argv);
	else
		ft_noheredoc(&d, argv);
	d.paths = ft_getallpaths(envp);
	if (!d.paths)
		exit(1);
	while (d.i < argc - 1)
		ft_loop(argc, argv, envp, &d);
	ft_freearr(d.paths);
	return (0);
}
