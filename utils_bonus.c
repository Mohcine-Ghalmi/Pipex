/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:10:20 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/22 22:34:49 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}


void	here_doc(char **av, int infile)
{
	char	*str;
	char 	*end;
    
	end = ft_strjoin(av[2], "\n");
	str = get_next_line(STDIN_FILENO);
	if (!str)
		exit(1);
	while (end && strcmp(end ,str) != 0)
	{
		ft_putstr_fd(str, infile);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
    free(end);
}