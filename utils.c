/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:30:31 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/15 15:07:07 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// working 
char    *ret_path(char **envp)
{
    while (ft_strncmp("PATH", *envp, 4))
        envp++;
    return (*envp + 5);
}

char    *command(char **paths, char *cmd)
{
    char *tmp;
    char *command;

    while (*paths)
    {
        tmp = ft_strjoin(*paths, "/");
        command = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(command, 0) == 0)
            return command;
        free(command);
        paths++;
    }
    return NULL;
}

void    close_pipes(int pipe[2])
{
    close(pipe[READ]);
    close(pipe[WRITE]);
    exit(1);
}