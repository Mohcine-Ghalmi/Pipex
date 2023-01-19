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

char    *Path_Line(char **envp)
{
    while (ft_strncmp("PATH", *envp, 4))
        envp++;
    return (*envp + 5);
}

char    *Path_Join_Cmd(char **Paths_Separated, char *In_Cmd)
{
    char    *to_join;
    char    *out_cmd;

    while (*Paths_Separated)
    {
        to_join = ft_strjoin(*Paths_Separated, "/");
        out_cmd = ft_strjoin(to_join, In_Cmd);
        free(to_join);
        if (access(out_cmd , X_OK) == 0)
            return out_cmd;
        free(out_cmd);
        Paths_Separated++;
    }
    return NULL;
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    char *path;
    char **path_cmd;
    char *cmd;

    path = Path_Line(envp);
    path_cmd = ft_split(path, ':');

    cmd = Path_Join_Cmd(path_cmd, argv[1]);
    printf("%s", cmd);
    return 0;
}