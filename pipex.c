/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:30:29 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/16 09:34:00 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void proc_child1(int infile, char *cmd1, char **cmd_path,int pipe[2], char **envp)
{
	char **args;
	char *cmd;
	
	dup2(pipe[WRITE], STDOUT_FILENO);
	close(pipe[READ]);
	dup2(infile, STDIN_FILENO);
	args = ft_split(cmd1 , ' ');
	cmd = command(cmd_path, args[0]);
	if (!cmd)
	{
		perror("command");
		exit(1);
	}
	exceve(cmd, args, envp);
}

void	proc_child2(int outfile, char *cmd2, char **cmd_path, int pipe[2], char **envp)
{
	dup2()
}

void	pipex(int infile,char *cmd1, int outfile, char *cmd2, char **envp , int pipe[2])
{
	char	**cmd_path;
	int pid_child1;
	int pid_child2;

	cmd_path = ft_split(ret_path(envp), ':');
	pid_child1 == fork();
	if (pid_child1 == -1)
		close_pipes(pipe);
}

int main(int argc, char **argv, char **envp)
{
	int pipe[2];
	int infile;
	int outfile;
	
	if (argc - 1 != 4)
		return (ft_printf("more or less number of arguments"));
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile == -1 || outfile == -1)
	{
		perror("open");
		exit(1);
	}
	if(pipe(pipe) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pipex(infile, argv[2], outfile, argv[4], envp, pipe);
	return 0;
}

