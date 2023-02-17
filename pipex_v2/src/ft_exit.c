/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:37:56 by kkaczoro          #+#    #+#             */
/*   Updated: 2023/01/19 16:21:51 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(t_data d, char *s)
{
	perror(s);
	ft_freearr(d.args);
	ft_freearr(d.paths);
	free(d.path);
	exit(-1);
}
