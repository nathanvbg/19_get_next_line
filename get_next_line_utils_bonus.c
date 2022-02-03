/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:40:35 by naverbru          #+#    #+#             */
/*   Updated: 2022/02/03 15:40:51 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	i = -1;
	j = -1;
	len = 0;
	while (s2[len] != '\n' && s2[len])
		len++;
	if (s2[len] == '\n')
		len++;
	len += ft_strlen(s1);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j] && s2[j] != '\n')
		dest[i + j] = s2[j];
	if (s2[j] == '\n')
		dest[i + j++] = '\n';
	dest[i + j] = '\0';
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
	return (&str[i]);
}

char	*ft_strndup(const char *str, char c)
{
	int		i;
	int		len;
	char	*dest;
	char	*src;

	src = (char *)str;
	i = 0;
	len = 0;
	while (src[len] && src[len] != c)
		len++;
	if (src[len] == '\n' && c == '\n')
		len++;
	dest = malloc(len + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
