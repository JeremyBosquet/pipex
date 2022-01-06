/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:51:14 by jbosquet          #+#    #+#             */
/*   Updated: 2021/12/10 16:36:09 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_pipex
{
	char	**argv;
	char	**envp;
	char	**cmd1;
	char	**cmd2;
	char	*infile;
	char	*outfile;
	pid_t	child;
	pid_t	child2;
	int		fds[2];
	char	**path;
	int		status;
}	t_pipex;

t_pipex	ft_init(char **argv, char **envp);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strjoin_free(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_str_ptr_str(char **str, const char *to_find);
void	ft_error(int errcode);
void	ft_err_msg(t_pipex *pipex, char *msg, char *err, int opt);
char	*ft_which_shell(char **envp);
void	ft_free_struct(t_pipex *pipex);
void	ft_free_cmd(char **cmd);

#endif