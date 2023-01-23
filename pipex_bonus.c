/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:24:34 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/23 15:42:57 by mghalmi          ###   ########.fr       */
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

void	pipex(char *cmd, char **env, int infile)
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
		if (infile == STDIN_FILENO)
			exit(1);
		else
			exec(cmd, env);
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
	int	i;

	i = 3;
	if (argc >= 5)
	{
		check_space(av, argc);
		if (ft_strncmp(av[1], "here_doc", 9) == 0)
		{
			infile = open("tmp.txt", O_CREAT | O_RDWR | O_APPEND, 0777);
			here_doc(av, infile);
			i = 4;
		}
		else
			infile = openfile(av[1], STDIN_FILENO);
		outfile = openfile(av[argc - 1], STDOUT_FILENO);
		if (infile == -1)
			exit(1);
		dup2(infile, STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		pipex(av[i - 1], env, infile);
		while (i < argc - 2)
			pipex(av[i++], env, STDOUT_FILENO);
		unlink("tmp.txt");
		exec(av[i], env);
	}
	write(STDERR_FILENO, "Invalid number of arguments.\n", 29);
}
