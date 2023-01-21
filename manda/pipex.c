/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:08:05 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/21 11:55:07 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(t_pipe var, char *cmd, char **envp)
{
	var.cmd_opt = ft_split(cmd, ' ');
	var.cmd = path_join_cmd(var.paths_cmd, var.cmd_opt[0]);
	if (!ft_check_env(var.cmd))
		free_child(&var);
	dup2(var.in_out[1], STDOUT_FILENO);
	close(var.in_out[0]);
	dup2(var.infile, 0);
	execve(var.cmd, var.cmd_opt, envp);
}

void	child2(t_pipe var, char *cmd, char **envp)
{
	var.cmd_opt = ft_split(cmd, ' ');
	var.cmd = path_join_cmd(var.paths_cmd, var.cmd_opt[0]);
	if (!ft_check_env(var.cmd))
		free_child(&var);
	dup2(var.in_out[0], STDIN_FILENO);
	close(var.in_out[1]);
	dup2(var.outfile, 1);
	execve(var.cmd, var.cmd_opt, envp);
}

void	pipex(char **argv, char **envp)
{
	t_pipe	var;

	var.infile = open(argv[1], O_RDONLY);
	var.outfile = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (var.infile < 0 || var.outfile < 0)
		ft_putstr_fd("can't open this file", 2);
	if (pipe(var.in_out) < 0)
	{
		perror("pipe");
		exit(1);
	}
	var.paths_cmd = ft_split(path_line(envp), ':');
	var.pid1 = fork();
	if (var.pid1 == 0)
		child1(var, argv[2], envp);
	var.pid2 = fork();
	if (var.pid2 == 0)
		child2(var, argv[3], envp);
	close(var.in_out[1]);
	close(var.in_out[0]);
	waitpid(var.pid1, NULL, 0);
	waitpid(var.pid2, NULL, 0);
	free_all(&var);
}

int	main(int argc, char **argv, char **envp)
{
	int		cond;
	int		i;

	i = 0;
	cond = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			cond = 1;
		i++;
	}
	if (cond == 0)
	{
		ft_putstr_fd("Error ENVP", 2);
		exit(1);
	}
	if (argc - 1 != 4)
	{
		ft_putstr_fd("more or less data ", 2);
		exit(1);
	}
	pipex(argv, envp);
	return (0);
}
