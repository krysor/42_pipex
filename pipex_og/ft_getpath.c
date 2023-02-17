/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:58:56 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/01/12 12:31:27 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_getpath_exit(char *cmd, char **paths, char *s, char **arr);
static char	**ft_arrdup(char **arr);
static char	*ft_findpath(char *cmd, char **arr, char *s, char **paths);

char	*ft_getpath(char *cmd, char **paths)
{
	char	*s;
	char	**arr;
	char	*path;

	s = ft_strjoin("/", cmd);
	if (!s || !cmd)
		ft_getpath_exit(cmd, paths, s, NULL);
	arr = ft_arrdup(paths);
	if (!arr)
		ft_getpath_exit(cmd, paths, s, NULL);
	path = ft_findpath(cmd, arr, s, paths);
	ft_freearr(arr);
	free(s);
	if (!path)
	{
		if (!access(cmd, X_OK))
			return (cmd);
		perror(NULL);
	}
	free(cmd);
	return (path);
}

static void	ft_getpath_exit(char *cmd, char **paths, char *s, char **arr)
{
	free(cmd);
	ft_freearr(paths);
	free(s);
	ft_freearr(arr);
	exit(-1);
}

static char	**ft_arrdup(char **arr)
{
	int		i;
	char	**dup;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
		i++;
	dup = malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		dup[i] = ft_strdup(arr[i]);
		if (!dup[i])
		{
			ft_freearr(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

static char	*ft_findpath(char *cmd, char **arr, char *s, char **paths)
{
	int		i;
	char	*temp;

	i = 0;
	while (arr[i])
	{
		temp = ft_strjoin(arr[i], s);
		if (!temp)
			ft_getpath_exit(cmd, paths, s, arr);
		free(arr[i]);
		arr[i++] = temp;
	}
	i = 0;
	while (arr[i])
	{
		if (!access(arr[i], X_OK))
			break ;
		i++;
	}
	temp = ft_strdup(arr[i]);
	return (temp);
}
