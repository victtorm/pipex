/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:49:03 by vbritto-          #+#    #+#             */
/*   Updated: 2024/05/16 13:53:28 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft/libft.h"

void	exec(char *argv, char **envp);
void	ft_clean(char **str);
void	parent_process(char **argv, char **envp, int *fd);
void	child_process(char **argv, char **envp, int *fd);
void	ft_error(int i);
bool	check_argument(char **argv, int argc);

#endif