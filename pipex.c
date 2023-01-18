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

void pipex(int infile, char *cmd1, int outfile, char *cmd2, char **envp)
{
	int pipe[2];
	int pid_child1;
	int pid_child2;
	
	if (pipe(pipe) < 0)
		err_p("pipe");
	pid_child1 = fork();
	
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
	pipex(infile)	
	return 0;
}
