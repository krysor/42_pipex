/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:42:06 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/01/16 17:12:29 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_data
{
	int		pip[2];
	int		fd;
	int		i;
	pid_t	pid;
	char	**args;
	char	*path;
	char	**paths;
}					t_data;
char	**ft_getallpaths(char *envp[]);
void	ft_freearr(char **arr);
char	*ft_getpath(char *cmd, char *envp[]);
char	*get_next_line(int fd);

#endif