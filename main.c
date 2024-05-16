/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:42:01 by vbritto-          #+#    #+#             */
/*   Updated: 2024/05/16 13:47:43 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5 || check_argument(argv, argc) == false)
		ft_error(1);
	if (pipe(fd) == -1)
		ft_error(2);
	pid = fork();
	if (pid == -1)
		ft_error(3);
	if (pid == 0)
		child_process(argv, envp, fd);
	waitpid(pid, NULL, 0);
	parent_process(argv, envp, fd);
	return (0);
}
