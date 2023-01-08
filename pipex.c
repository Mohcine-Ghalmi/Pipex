/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:30:29 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/08 14:39:48 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char *infile, char *outfile, char **argv, char **envp)
{
	int fdfiles[2];
	int cpid;
	pid_t child1;
	pid_t child2;

	if (pipe(fdfiles) == -1)
		return -1;
	child1 = fork();
	if (child1 < 0);
		return (perror("Fork: "));
	if (child1 == 0)
		first_child(infile, argv[2]);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		second_child(outfile, argv[4]);
}

int main(int argc, char **argv, char **envp)
// envp: the environmental variable --> all possible PATH to the command binaries
{
	int	infile;
	int	outfile;

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_CREAT | O_RDWR , 0644);
	if (infile < 0 || outfile < 0)
		return -1;
	//pipex function
	pipex(infile, outfile, argv, envp);
	return 0;
}