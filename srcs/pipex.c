/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:17:35 by jbosquet          #+#    #+#             */
/*   Updated: 2021/12/13 19:44:48 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_which(char *cmd, t_pipex *pipex)
{
	int		i;
	int		y;
	char	*tmp;
	char	**cmd_tmp;
	char	*tmp_free;

	if (!access(cmd, 0))
		return (cmd);
	i = -1;
	if (!pipex->path)
		return (0);
	while (pipex->path[++i])
	{
		y = 0;
		cmd_tmp = ft_split(cmd, ' ');
		tmp_free = ft_strjoin(pipex->path[i], "/");
		tmp = ft_strjoin(tmp_free, cmd_tmp[0]);
		free(tmp_free);
		ft_free_cmd(cmd_tmp);
		if (!access(tmp, 0))
			return (tmp);
		else
			free(tmp);
	}
	return (0);
}

static void	ft_pipex_2(t_pipex *pipex, int *fds)
{
	int		outfile;
	char	*path;

	outfile = open(pipex->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		ft_err_msg(pipex, "no such file or directory: ", pipex->outfile, 0);
	dup2(fds[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fds[1]);
	path = ft_which(pipex->argv[3], pipex);
	if (!access(path, 0))
		execve(path, pipex->cmd2, pipex->envp);
	ft_err_msg(pipex, "command not found: ", pipex->argv[3], 1);
}

static void	ft_pipex(t_pipex *pipex, int *fds)
{
	int		infile;
	char	*path;

	infile = open(pipex->argv[1], O_RDONLY);
	if (infile == -1)
		ft_err_msg(pipex, "no such file or directory: ", pipex->infile, 0);
	dup2(fds[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fds[0]);
	path = ft_which(pipex->argv[2], pipex);
	if (!access(path, 0))
		execve(path, pipex->cmd1, pipex->envp);
	ft_err_msg(pipex, "command not found: ", pipex->argv[2], 0);
}

void	ft_end(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd1[i])
		free(pipex->cmd1[i++]);
	free(pipex->cmd1);
	i = 0;
	while (pipex->cmd2[i])
		free(pipex->cmd2[i++]);
	free(pipex->cmd2);
	i = 0;
	while (pipex->path[i])
		free(pipex->path[i++]);
	free(pipex->path);
	close(pipex->fds[0]);
	close(pipex->fds[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		write(1, "Syntax: ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 50);
		return (127);
	}
	pipex = ft_init(argv, envp);
	if (pipe(pipex.fds) == -1)
		ft_error(0);
	pipex.child = fork();
	if (pipex.child < 0)
		ft_error(0);
	if (!pipex.child)
		ft_pipex(&pipex, pipex.fds);
	pipex.child2 = fork();
	if (pipex.child2 < 0)
		ft_error(0);
	if (pipex.child2 == 0)
		ft_pipex_2(&pipex, pipex.fds);
	ft_end(&pipex);
	waitpid(pipex.child, &pipex.status, 0);
	waitpid(pipex.child2, &pipex.status, 0);
	exit (WEXITSTATUS(pipex.status));
}
