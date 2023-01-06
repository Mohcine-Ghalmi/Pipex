/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:30:29 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/06 13:18:44 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void first_proc(int f1, char *cmd1) // child proc
{
	dup2(f1, STDIN_FILENO);
}

void second_proc() // parent proc 
{
	
}

void pipex(int f1,int f2, char *cmd1, char *cmd2)
{
	int fds[2];
	pid_t proc;

	pipe(fds);
	// 
	proc = fork();
	if (proc < 0)
		return (perror("Fork: "));
	if (!proc) //if proc > 0 then it's the child end[0] proc cuz it's runs first  
		first_proc(f1, cmd1);
	else // if proc = 0 thene it's the parent end[1] proc cause  it's runs in the end 
		second_proc(f2, cmd2);
}

int main(int argc, char **argv, char **envp)
// envp: the environmental variable --> all possible PATH to the command binaries
{
	int	f1;
	int	f2;

	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDONLY | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
	{
		perror("open :");
		return 0;
	}
	pipex(f1, f2, argv, envp);
}