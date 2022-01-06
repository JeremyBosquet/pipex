/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:58:14 by jbosquet          #+#    #+#             */
/*   Updated: 2021/12/10 16:35:48 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipex	ft_init(char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.argv = argv;
	pipex.envp = envp;
	pipex.cmd1 = ft_split(argv[2], ' ');
	pipex.cmd2 = ft_split(argv[3], ' ');
	pipex.infile = argv[1];
	pipex.outfile = argv[4];
	pipex.path = ft_split(ft_str_ptr_str(envp, "PATH="), ':');
	pipex.status = 127;
	return (pipex);
}

void	ft_free_cmd(char	**cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}
