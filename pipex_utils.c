/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:35:32 by vbritto-          #+#    #+#             */
/*   Updated: 2024/05/04 19:14:23 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clean(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
}

void	cmd_or_path_error(char **cmd, char **all_path, char *argv)
{
	char *error;

	error = ft_strjoin("command not found: ", argv);
	perror(error);
	ft_clean(cmd);
	ft_clean(all_path);
	exit(EXIT_FAILURE);
}

void	exec(char *argv, char **envp)
{
	char	**cmd;
	char	**all_path;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(argv, 32);
	while (strncmp(envp[i], "PATH", 4) != 0)
		i++;
	all_path = ft_split(envp[i] + 5, 58);
	i = 0;
	while (all_path[i] != NULL)
	{
		path = ft_strjoin(ft_strjoin(all_path[i], (char *)"/"), cmd[0]);
		if (access(path, X_OK) == 0)
			execve(path, cmd, envp);
		free(path);
		i++;
	}
	cmd_or_path_error(cmd, all_path, argv);
	ft_clean(all_path);
	return ;
}
