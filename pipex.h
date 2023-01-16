/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:30:31 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/15 15:06:27 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# define READ 0
# define WRITE 1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <errno.h>
#include <sys/wait.h>

char    *ret_path(char **envp);
void    pipex(int infile, int cmd1, int cmd2, int outfile, char **envp);
void    close_pipes(int pipe[2]);
char    *command(char **paths, char *cmd);

#endif