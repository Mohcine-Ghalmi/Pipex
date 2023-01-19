/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:07:20 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/18 16:08:22 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void err_m(char *msg)
{
    write(1, msg, ft_strlen(msg));
    exit(1);
}

void err_p(char *msg)
{
    perror(msg);
    exit(1);
}

void    child_free(char **cmd_arg, char *cmd)
{
    free(cmd_arg);
    free(cmd);
}

void    parent_free(int infile, int outfile, )

void close_pipes(int pipe[2])
{
    close(pipe[READ]);
    close(pipe[WRITE]);
}