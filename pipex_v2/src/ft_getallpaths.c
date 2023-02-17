/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getallpaths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:23:35 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/01/18 13:19:54 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_getallpaths(char *envp[])
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
			break ;
		i++;
	}
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	return (paths);
}
