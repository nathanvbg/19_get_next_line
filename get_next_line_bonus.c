/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:22:54 by naverbru          #+#    #+#             */
/*   Updated: 2022/02/10 13:22:59 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_endfree(char **str, char **buf)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	if (buf != NULL)
	{
		free(*buf);
		*str = NULL;
	}
	return (NULL);
}

char	*ft_free(char **str)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*ft_process(char **rest, int fd, int ret)
{
	char	*line;
	char	*buf;
	char	*tmp;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (ft_free(rest));
	line = ft_strjoin("", *rest);
	if (!line)
		return (ft_endfree(rest, &buf));
	ft_free(rest);
	while (ret > 0 && is_charset(line) != 1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0 && ft_strlen(line) == 0)
			return (ft_endfree(&line, &buf));
		buf[ret] = '\0';
		tmp = line;
		line = ft_strjoin(line, buf);
		if (!line)
			return (ft_endfree(&tmp, &buf));
		free(tmp);
	}
	return (ft_endprocess(&line, &buf, &rest));
}

char	*ft_endprocess(char **line, char **buf, char ***rest)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strndup(*line, '\n');
	if (!line)
		return (ft_endfree(&tmp, buf));
	**rest = ft_strndup(ft_strchr(tmp, '\n'), '\0');
	free(tmp);
	if (**rest == NULL)
		return (ft_endfree(line, buf));
	ft_free(buf);
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*line;
	int			ret;

	ret = 1;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (rest[fd] == NULL)
		rest[fd] = ft_strndup("", '\0');
	if (rest[fd] == NULL)
		return (NULL);
	line = ft_process(&rest[fd], fd, ret);
	return (line);
}

/*
#include <stdio.h>
int	main()
{
	char	*line;
	int		fd;

	fd = open("alternate_line_nl_with_nl", O_RDONLY);
	printf("%s", get_next_line(fd));
	while ((line = get_next_line(fd)))
		printf("%s", line);
	close(fd);
	return (0);
}
*/
