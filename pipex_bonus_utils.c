/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:34:00 by vbritto-          #+#    #+#             */
/*   Updated: 2024/05/23 12:49:44 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_clean(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	cmd_or_path_error(char **cmd, char **all_path, char *argv)
{
	char	*error;

	error = ft_strjoin("command not found: ", argv);
	perror(error);
	free(error);
	ft_clean(cmd);
	ft_clean(all_path);
	exit(EXIT_FAILURE);
}

void	exec_bonus(char *argv, char **envp)
{
	char	**cmd;
	char	**all_path;
	char	*path;
	char	*path_temp;
	int		i;

	i = 0;
	cmd = ft_split(argv, 32);
	while (strncmp(envp[i], "PATH", 4) != 0)
		i++;
	all_path = ft_split(envp[i] + 5, 58);
	i = 0;
	while (all_path[i] != NULL)
	{
		path_temp = ft_strjoin(all_path[i], (char *)"/");
		path = ft_strjoin(path_temp, cmd[0]);
		if (access(path, X_OK) == 0)
			execve(path, cmd, envp);
		free(path);
		free(path_temp);
		i++;
	}
	cmd_or_path_error(cmd, all_path, argv);
}

void	exit_here_doc(int file)
{
	get_next_line(-1);
	close(file);
	unlink("here_doc");
	exit(EXIT_FAILURE);
}
