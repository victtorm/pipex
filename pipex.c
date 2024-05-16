/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:34:15 by vbritto-          #+#    #+#             */
/*   Updated: 2024/05/16 17:15:48 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	check_argument(char **argv, int argc)
{
	argc--;
	while (argc > 1)
	{
		if (argv[argc][0] == '\0' || argv[argc][0] == ' ')
			return (false);
		argc--;
	}
	return (true);
}

void	ft_error(int i)
{
	if (i == 1)
	{
		write(2, "Error: Invalid Arguments\n", 25);
		write(2, "Try: ./pipex file1 cmd1 cmd2 file2\n", 35);
	}
	else if (i == 2)
		perror("Error: Pipe\n");
	else if (i == 3)
		perror("Error: Fork\n");
	else if (i == 4)
		perror("Error: File descriptor\n");
	else if (i == 5)
		perror("Error: no such file or directory\n");
	exit(EXIT_FAILURE);
}

void	child_process(char **argv, char **envp, int *fd)
{
	int	file;

	file = open(argv[1], O_RDONLY, 0644);
	if (file == -1)
		ft_error(4);
	close(fd[0]);
	dup2(file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(file);
	close(fd[1]);
	exec(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	file;

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
		ft_error(4);
	close(fd[1]);
	dup2(file, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(file);
	close(fd[0]);
	exec(argv[3], envp);
}
