/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:52:38 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/18 16:45:23 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *path_line(char **envp)
{
    while (ft_strncmp("PATH", *envp, 4))
        envp++;
    return (*envp + 5);
}

int main(int argc, char **argv, char **envp)
{
    char *path;
    char **path_cmd;

    path = path_line(envp);
    path_cmd = ft_split(path, ':');
    printf("%s\n", path);

    for (int i = 0; i < strlen(*path_cmd); i++)
        printf("%s\n", path_cmd[i]);
}