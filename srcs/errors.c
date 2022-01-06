/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:56:56 by jbosquet          #+#    #+#             */
/*   Updated: 2021/12/10 12:44:43 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_struct(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->path[i])
		free(pipex->path[i++]);
	free(pipex->path);
}

void	ft_error(int errcode)
{
	perror("pipex");
	exit(errcode);
}

void	ft_err_msg(t_pipex *pipex, char *msg, char *err, int opt)
{
	char	*shell;

	shell = ft_strjoin("zsh: ", msg);
	shell = ft_strjoin_free(shell, err);
	shell = ft_strjoin_free(shell, "\n");
	write(2, shell, ft_strlen(shell));
	free(shell);
	if (opt)
		ft_free_struct(pipex);
	exit(127);
}
