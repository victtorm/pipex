/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:46:54 by vbritto-          #+#    #+#             */
/*   Updated: 2024/05/16 19:11:43 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_bonus(int i)
{
	if (i == 1)
	{
		write(2, "Error: Invalid Arguments\n", 25);
		write(2, "Try: ./pipex file1 cmd1 cmd2 cmd3 ... file2\n", 44);
		write(2, "Or: ./pipex here_doc cmd1 cmd2 cmd3 file2\n", 42);
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

void	start_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error_bonus(2);
	pid = fork();
	if (pid == -1)
		ft_error_bonus(3);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		exec(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter)
{
	char	*line;
	int		file;

	file = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file == -1)
		ft_error_bonus(4);
	while (1)
	{
		write(1, "heredoc>", 8);
		line = get_next_line(0);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		write(file, line, ft_strlen(line));
		free(line);
	}
	close(file);
}

bool	check_bonus(int argc, char **argv)
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

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	i;

	i = 2;
	if (check_bonus(argc, argv) == false)
		ft_error_bonus(1);
	if (ft_strncmp(argv[1], "here_doc\0", 9) == 0 && argc == 6)
	{
		i++;
		fd[1] = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0666);
		here_doc(argv[2]);
	}
	else
		fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd[0] = open(argv[1], O_RDONLY, 0644);
	if (fd[0] == -1)
		ft_error_bonus(4);
	dup2(fd[0], STDIN_FILENO);
	while (i < argc - 1)
		start_process(argv[i++], envp);
	dup2(fd[1], STDOUT_FILENO);
	unlink("here_doc");
	close(fd[1]);
	//exec(argv[argc - 2], envp);
}
