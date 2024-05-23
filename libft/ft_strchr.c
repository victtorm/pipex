/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:41:33 by vbritto-          #+#    #+#             */
/*   Updated: 2024/05/16 13:55:48 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str++ == (char)c)
			return ((char *)--str);
	}
	if ((char)c == *str)
		return ((char *)str);
	return ((char *)0);
}
/*
#include<stdio.h>
#include<string.h>

int main()
{
	char	str[] = "555test555";

	printf("%s", ft_strchr(str, 5));
}*/
