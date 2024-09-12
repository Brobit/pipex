/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:31:59 by almarico          #+#    #+#             */
/*   Updated: 2024/09/12 10:25:40 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"
#include <sys/wait.h>
#include <unistd.h>

void	path(char *cmd_line, char **env)
{
	char	**cmd;
	char	**all_path;
	char	*cmd_to_add;
	char	*cmd_path;
	int		i;

	i = 0;
	while (ft_strncmp(env[i], PATH, ft_strlen(PATH)) != 0)
		i++;
	all_path = ft_split(env[i] + ft_strlen(PATH), ':');
	cmd = ft_split(cmd_line, ' ');
	cmd_to_add = ft_strjoin("/", *cmd);
	i = 0;
	while (all_path[i])
	{
		cmd_path = ft_strjoin(all_path[i++], cmd_to_add);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free_essential(all_path, cmd_to_add);
			execve(cmd_path, cmd, env);
			return (free_essential(cmd, cmd_path), error(ERR_EXECVE));
		}
		free(cmd_path);
	}
	return (free_all(all_path, cmd, cmd_to_add), error(ERR_PATH));
}

void	start_proces1(char *infile, char *cmd_line, int *pipefd, char **env)
{
	int	infile_fd;

	infile_fd = open(infile, O_RDONLY);
	if (infile_fd == -1)
		error(ERR_INFILE);
	close(pipefd[0]);
	if (dup2(infile_fd, 0) == -1 || dup2(pipefd[1], 1) == -1)
		error(ERR_DUP2);
	path(cmd_line, env);
}

void	start_process2(char *outfile, char *cmd_line, int *pipefd, char **env)
{
	int	outfile_fd;

	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfile_fd == -1)
		error(ERR_OUTFILE);
	close(pipefd[1]);
	if (dup2(pipefd[0], 0) == -1 || dup2(outfile_fd, 1) == -1)
		error(ERR_DUP2);
	path(cmd_line, env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	process1;
	pid_t	process2;
	int		waiter;

	if (argc != 5)
		error(ERR_ARGC);
	if (pipe(pipefd) == -1)
		error(ERR_PIPE);
	process1 = fork();
	if (process1 == -1)
		error(ERR_FORK);
	else if (process1 == 0)
		start_proces1(argv[1], argv[2], pipefd, env);
	process2 = fork();
	if (process2 == -1)
		error(ERR_FORK);
	else if (process2 == 0)
		start_process2(argv[4], argv[3], pipefd, env);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(process1, &waiter, 0);
	waitpid(process2, &waiter, 0);
	return (SUCCESS);
}
