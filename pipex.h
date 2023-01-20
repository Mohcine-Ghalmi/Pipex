/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:11:43 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/20 13:11:14 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <err.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_pipe
{
    pid_t   pid1;
    pid_t   pid2;
    int     in_out[2];
    int     infile;
    int     outfile;
    char    **paths_cmd;
    char    **cmd_opt;
    char    *cmd;
}   t_pipe;

void    child1(t_pipe var, char *cmd, char **envp);
void    child2(t_pipe var, char *cmd, char **envp);
void    pipex(char **argv, char **envp);
char    *Path_Line(char **envp);
char    *Path_Join_Cmd(char **Paths_Separated, char *Cmd);
int    ft_check_env(char   *path);
void    free_child(t_pipe *var);
void    free_all(t_pipe *var);

#endif