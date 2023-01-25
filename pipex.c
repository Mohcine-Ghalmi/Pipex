/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:24:34 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/25 10:23:10 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile(char *filename, int mode)
{
	if (mode == STDIN_FILENO)
	{
		if (access(filename, F_OK))
		{
			write(STDERR_FILENO, filename, ft_strchr1(filename, 0));
			write(STDERR_FILENO, ": No such file or directory\n", 28);
			return (-1);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644));
}

char	*getpath(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && ft_strchr1(path, ':') > 0)
	{
		dir = ft_strdup1(path, ft_strchr1(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strchr1(path, ':') + 1;
	}
	return (cmd);
}

void	exec(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = getpath(args[0], env);
	if (execve(path, args, env) < 0)
	{
		write(STDERR_FILENO, cmd, ft_strchr1(cmd, 0));
		write(STDERR_FILENO, ": command not found\n", 20);
	}
	exit(1);
}

void	pipex1(char *cmd, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];

	pid1 = fork();
	pid2 = fork();
	if (pid1 == -1 || pid2 == -1 || pipe(pipefd) < 0)
		exit(1);
	if (pid1)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		exec(cmd, env);
		exit(1);
	}
	if (pid2)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **av, char **env)
{
	int	infile;
	int	outfile;

	if (ft_strspace(av[2]) > 0 || ft_strspace(av[3]) > 0)
	{
		write(STDERR_FILENO, "Missing Command\n", 17);
		return (0);
	}
	if (argc == 5)
	{
		infile = openfile(av[1], STDIN_FILENO);
		outfile = openfile(av[4], STDOUT_FILENO);
		if (infile == -1)
			exit(1);
		dup2(infile, STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		pipex1(av[2], env);
		exec(av[3], env);
	}
	else
		write(STDERR_FILENO, "Invalid number of arguments.\n", 29);
	return (0);
}
