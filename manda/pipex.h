/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:11:43 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/20 16:09:41 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <err.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pipe
{
	pid_t	pid1;
	pid_t	pid2;
	int		in_out[2];
	int		infile;
	int		outfile;
	char	**paths_cmd;
	char	**cmd_opt;
	char	*cmd;
}	t_pipe;

void	child1(t_pipe var, char *cmd, char **envp);
void	child2(t_pipe var, char *cmd, char **envp);
void	pipex(char **argv, char **envp);
char	*path_line(char **envp);
char	*path_join_cmd(char **Paths_Separated, char *Cmd);
int		ft_check_env(char	*path);
void	free_child(t_pipe *var);
void	free_all(t_pipe *var);
size_t	ft_strlen(const char *s);
int		count_words(char const *s, char c);
int		word_size(char const *s, char c);
void	*ft_free(char **split);
char	*words(char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

#endif
