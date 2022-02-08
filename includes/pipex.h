/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:45:50 by adubeau           #+#    #+#             */
/*   Updated: 2021/12/17 12:58:18 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlen(const char *str);
void					ft_putchar(char c, int fd);
void					ft_putstr_fd(char *str, int fd);
size_t					ft_strlcpy(char *dest, const char *src, size_t n);
char					**ft_split(char const *s, char c);
char					*ft_getPath(char **envp);
char					**ft_getCmd(char **argv, int n);
void					ft_exec(char **argv, char **envp,  int n);
void					ft_child(int *end, char **envp, char **argv);
void					ft_parent(int *end, char **envp, char **argv, pid_t *child);
void					pipex(int *end, char **envp, char **argv);
int					main(int argc, char **argv, char **envp);

#endif
