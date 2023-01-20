/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:34:37 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/20 12:26:59 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *Path_Line(char **envp)
{
    while (ft_strncmp("PATH", *envp, 4))
        envp++;
    return (*envp + 5);
}

char    *Path_Join_Cmd(char **Paths_Separated, char *Cmd)
{
    char    *to_join;
    char    *out_cmd;

    // printf("dhgsdk\n");
    while (*Paths_Separated)
    {
        to_join = ft_strjoin(*Paths_Separated, "/");
        out_cmd = ft_strjoin(to_join, Cmd);
        free(to_join);
        if (access(out_cmd , X_OK) == 0)
            {return out_cmd;}
        free(out_cmd);
        Paths_Separated++;
    }
    return NULL;
}

int    ft_check_env(char   *path)
{
    if (!path)
    {
        ft_putstr_fd("env not found", 2);
        return 0;
    }
    return 1;
}

void free_child(t_pipe *var)
{
    int	i;

	i = 0;
	close(var->infile);
	close(var->outfile);
	while (var->paths_cmd[i])
		free(var->paths_cmd[i++]);
	free(var->paths_cmd);
    exit(1);
}

void    free_all(t_pipe *var)
{
    int i;

    i = 0;
    close(var->infile);
    close(var->outfile);
    while(var->paths_cmd[i])
        free(var->paths_cmd[i++]);
    free(var->paths_cmd);
}