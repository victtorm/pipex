/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:00:31 by vbritto-          #+#    #+#             */
/*   Updated: 2024/05/18 14:16:53 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	n;
	char			*str;	

	j = 0;
	n = 0;
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!s1)
		s1 = ft_calloc(sizeof(char), 1);
	str = (char *)malloc(i + 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (s1[n] != '\0')
		str[j++] = s1[n++];
	n = 0;
	while (s2[n] != '\0')
		str[j++] = s2[n++];
	str[j] = 0;
	return (str);
}
/*
char	*ft_strjoin(char *s1, const char *s2)
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
	while (s1[i++])
		new[i] = s1[i];
	j = -1;
	while (s2[j++])
		new[i + j] = s2[j];
	new[i + j] = '\0';
	return (new);
}*/

/*
int main(int argc, char **argv)
{
    printf("%s", ft_strjoin(argv[argc - 2], argv[argc - 1]));
}*/
