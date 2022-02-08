/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:53:26 by adubeau           #+#    #+#             */
/*   Updated: 2021/10/02 03:00:11 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char    *ft_getPath(char **envp)
{
        int i;

        i = 0;
        while (envp++)
        {
                if (envp[i][0] == 'P')
                        if (envp[i][1] == 'A')
                                return (*envp);
        }
        return (*envp);
}

char **ft_getCmd(char **argv, int n)
{
        return (ft_split(argv[n], ' '));
}

void    ft_exec(char **argv, char **envp,  int n)
{
        char **command;
        char **path;
        char *cmd;
        int i;

        i = -1;
        path = ft_split(ft_getPath(envp), ':');
        command = ft_getCmd(argv, n);
        while (path[++i])
        {
                cmd = ft_strjoin(ft_strjoin(path[i], "/"), command[0]);
                if (access(cmd, F_OK | X_OK) == 0)
                        break ;
                free(cmd);
        }
        if (access(cmd, F_OK) == 0)
                execve(cmd, (char *const *) command, envp);
        else
                ft_putstr_fd("Cette commande n'existe pas", 2);
        exit(1);
}
