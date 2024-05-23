/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:22:57 by vbritto-          #+#    #+#             */
/*   Updated: 2024/05/18 14:01:18 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinl(char *s1, const char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2[++j])
		new[i + j] = s2[j];
	free(s1);
	new[i + j] = '\0';
	return (new);
}

char	*ft_read(int fd, char *stash)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(stash, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stash = ft_strjoinl(stash, buffer);
		free(buffer);
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	int		len;
	int		i;

	if (!*stash)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*clean_stash(char *stash)
{
	char	*str;
	int		len;
	int		i;

	if (!*stash)
	{
		free(stash);
		return (NULL);
	}
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	str = malloc(sizeof(char) * (ft_strlen(stash) - len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[len])
		str[i++] = stash[++len];
	str[i] = '\0';
	free(stash);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd == -1)
		free (stash);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
