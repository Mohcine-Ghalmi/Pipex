/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:30:31 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/18 16:53:06 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// working 
char    *Path_Line(char **envp)
{
    while (ft_strncmp("PATH", *envp, 4))
        envp++;
    return (*envp + 5);
}

char **Paths_Separated(char *path)
{
    char *path;
	char **path_cmd;

	path = path_line(envp);
	path_cmd = ft_split(path, ':');

    return (path_cmd);
}

char    *Path_Join_Cmd(char **Paths_Separated, char *In_cmd)
{
    
}