/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:58:56 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/01/19 16:14:26 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_arrdup(char **arr);
static char	*ft_findpath(char **arr, char *s);

char	*ft_getpath(char *cmd, char **paths)
{
	char	*s;
	char	**arr;
	char	*path;

	s = ft_strjoin("/", cmd);
	if (!s)
		return (NULL);
	arr = ft_arrdup(paths);
	if (!arr)
	{
		free(s);
		return (NULL);
	}
	path = ft_findpath(arr, s);
	free(s);
	ft_freearr(arr);
	if (!path)
	{
		if (!access(cmd, X_OK))
			return (cmd);
	}
	return (path);
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

static char	*ft_findpath(char **arr, char *s)
{
	int		i;
	char	*temp;

	i = 0;
	while (arr[i])
	{
		temp = ft_strjoin(arr[i], s);
		if (!temp)
			return (NULL);
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
