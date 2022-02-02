/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:21:03 by naverbru          #+#    #+#             */
/*   Updated: 2022/02/02 18:54:00 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	//if (s1 == NULL || s2 == NULL)
	//	return (NULL);
	//printf("s1 = %s\ns2 = %s\n", s1, s2);
	while (s2[len] != '\n' && s2[len])
		len++;
	if (s2[len] == '\n')
		len++;
	len += ft_strlen(s1);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		dest[i + j] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
	{
		dest[i + j] = '\n';
		j++;
	}
	dest[i + j] = '\0';
	//printf("dest = %s\n", dest);
	return (dest);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i + 1]);
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (NULL);
}

char	*ft_strndup(const char *str)
{
	int		i;
	int		len;
	char	*dest;
	char	*src;

	src = (char *)str;
	printf("restoo = %s\n", src);
	i = 0;
	len = 0;
	while (src[len] && src[len] != '\n')
		len++;
	if (src[len] == '\n')
		len++;
	printf("len = %d\n", len);
	dest = malloc(len + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		printf("dest = %c\n", dest[i]);
		i++;
	}
	dest[i] = '\0';
	printf("dest = %s\n", dest);
	return (dest);
}
