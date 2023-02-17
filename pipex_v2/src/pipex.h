/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:42:06 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/01/20 11:17:58 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <limits.h>

typedef struct s_data
{
	int		fd;
	int		p_fff;
	int		i;
	int		pip[2];
	pid_t	pid;

	char	**args;
	char	**paths;
	char	*path;

	int		p_hd;
	char	*hd;
	char	*tmp;
	int		l;
	char	*s;
}					t_data;
void	ft_freearr(char **arr);
char	**ft_getallpaths(char *envp[]);
char	*ft_getpath(char *cmd, char **paths);
void	ft_noheredoc(t_data *d, char *argv[]);
void	ft_loop(int argc, char *argv[], char *envp[], t_data *d);
void	ft_exit(t_data d, char *s);
void	ft_fork(int argc, char *argv[], char *envp[], t_data *d);

#endif