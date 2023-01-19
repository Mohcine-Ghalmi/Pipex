/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:30:29 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/18 16:49:44 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	proc_child1(int pipe[2], int infile, char *cmd1, char **envp)
{
	char **cmd_arg;
	char *cmd;

	dup2(pipe[WRITE], STDOUT_FILENO);
	close(pipe[READ]);
	dup2(infile, STDIN_FILENO);
	cmd_arg = ft_split(cmd1, ' ');
	cmd = Path_Join_Cmd(cmd_arg, cmd_arg[0]);
	if (!cmd)
	{
		child_free(cmd_arg, cmd);
		err_m("no command found");
	}
	execve(cmd, cmd_arg, envp);
}

void	proc_child2(int pipe[2], int outfile, char *cmd2, char **envp)
{
	char **cmd_arg;
	char *cmd;

	dup2(pipe[READ], STDIN_FILENO);
	close(pipe[WRITE]);
	dup2(outfile, STDOUT_FILENO);
	cmd_arg = ft_split(cmd2, ' ');
	cmd = Path_Join_Cmd(cmd_arg, cmd_arg[0]);
	if (!cmd)
	{
		child_free(cmd_arg, cmd);
		err_m("no command found");
	}
	execve(cmd, cmd_arg, envp);
}

void pipex(int infile, char *cmd1, int outfile, char *cmd2, char **envp)
{
	int fds[2];
	int pid_child1;
	int pid_child2;
	
	if (pipe(fds) < 0)
		err_p("pipe");
	pid_child1 = fork();
	if (pid_child1 == 0)
		proc_child1(fds, infile, cmd1, envp);
	pid_child2 = fork();
	if (pid_child2 == 0)
		proc_child2(fds, outfile, cmd2, envp);
	close_pipes(fds);
	waitpid(pid_child1, NULL, 0);
	waitpid(pid_child1, NULL, 0);
}

int main(int argc, char **argv, char **envp)
{
	int infile;
	int outfile;
	
	if (argc - 1 != 4)
		return (0);
	infile = open(argv[1],O_RDONLY);
	outfile = open(argv[4], O_WRONLY, O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
		err_p("open");
	pipex(infile, argv[2], outfile, argv[4], envp);	
	return 0;
}
