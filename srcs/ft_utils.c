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

size_t ft_strlen(const char *str)
{
        int i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *str;
        int             i;
        int             j;

        i = 0;
        j = 0;
        str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
        if (!str)
                return (NULL);
        while (s1[i])
        {
                str[i] = s1[i];
                i++;
        }
        while (s2[j])
        {
                str[i + j] = s2[j];
                j++;
        }
        str[i + j] = '\0';
        return (str);
}

void    ft_putchar(char c, int fd)
{
        write(fd, &c, 1);
}

void    ft_putstr_fd(char *str, int fd)
{
        int     i;

        i = 0;
        while (str[i])
                ft_putchar(str[i++], fd);
        write(fd,"\n", 1);
}

