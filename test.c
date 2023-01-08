/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:52:36 by mghalmi           #+#    #+#             */
/*   Updated: 2023/01/08 18:31:46 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int main(void)
{
    pid_t pid1, pid2;
    pid_t ret;
    int status;

    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork:");
        return 1;
    }
    else if (!pid1)
    {
        printf("Child1: I am the 1st Child\n");
        return 2;
    }
    else
    {
        pid2 = fork();
        if (pid2 == -1)
        {
            perror("fork:");
            return 1;
        }
        else if (!pid2)
        {
            printf("Child2: I am the 2nd Child\n");
            return 3;
        }
        else
        {
            printf("Parent: I have  Children\n");
            ret = waitpid(pid1,&status, 0);
            printf("Parent: succefully got status from %d Child\n", ret);
            printf("Parent: Exit code is %d, signal is %d\n", WEXITSTATUS(status), WTERMSIG(status));
            ret = waitpid(pid2, &status, 0);
            printf("Parent: succefully got status from %d Child\n", ret);
            printf("Parent: Exit code is %d, signal is %d\n", WEXITSTATUS(status), WTERMSIG(status));
        }
    }
    return 0;
}
