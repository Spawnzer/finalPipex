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

void	ft_child(int *end, char **envp, char **argv)
{
	int f1;

	if ((f1 = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr_fd("fichier1 manquant", 2);
		exit (1);
	}
	close(end[0]);
	dup2(end[1], 1);
	close(end[1]);
	dup2(f1, 0);
	ft_exec(argv, envp, 2);
}

void	ft_parent(int *end, char **envp, char **argv, pid_t *child)
{
	int status;
	int f2;

	status = 0;
	waitpid(*child, &status, 0);
	if ((f2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0)
	{
		ft_putstr_fd("fichier2 manquant", 2);
		exit(1);
	}
	close(end[1]);
	dup2(end[0], 0);
	close(end[0]);
	dup2(f2, 1);
	ft_exec(argv, envp, 3);
}

void	pipex(int *end, char **envp, char **argv)
{
	pid_t	child;

	if ((child = fork()) < 0)
		return (perror("Bad fork"));
	else if (child == 0)
		ft_child(end, envp, argv);
	else if (child > 0)
		ft_parent(end, envp, argv, &child);
}

int main(int argc, char **argv, char **envp)
{
	int	end[2];

	if (argc != 5)
	{
		ft_putstr_fd("Entrez la commande sous la forme: \"./pipex fichier1 cmd1 cmd2 fichier2\"", 2); 
		exit(1);
	}
	if (pipe(end) == -1)
	{
		ft_putstr_fd("Bad pipe", 2);
		exit(1);
	}
	pipex(end, envp, argv);
	return (0);
}
