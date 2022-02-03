/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:40:17 by naverbru          #+#    #+#             */
/*   Updated: 2022/02/03 15:40:25 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

int	is_charset(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		if (str[i] == '\0')
			return (2);
		i++;
	}
	return (0);
}

char	*ft_process(char **rest, int fd)
{
	int		ret;
	char	*line;
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	line = ft_strndup(*rest, '\n');
	if (line == NULL)
		return (ft_free(rest));
	ft_free(rest);
	ret = read(fd, &buf, BUFFER_SIZE);
	buf[ret] = '\0';
	if (ret <= 0 && ft_strlen(line) == 0)
		return (ft_free(&line));
	while (ret > 0 && is_charset(buf) == 0)
	{
		tmp = line;
		line = ft_strjoin(line, buf);
		if (line == NULL)
			return (ft_free(&tmp));
		free(tmp);
		ret = read(fd, &buf, BUFFER_SIZE);
		buf[ret] = '\0';
	}
	return (ft_endprocess(&line, buf, &rest));
}

char	*ft_endprocess(char **line, char *buf, char ***rest)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buf);
	if (line == NULL)
		return (ft_free(&tmp));
	free(tmp);
	**rest = ft_strndup(ft_strchr(buf, '\n'), '\0');
	if (**rest == NULL)
	{
		free(*line);
		return (NULL);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (rest[fd] == NULL)
		rest[fd] = ft_strndup("", '\0');
	if (rest[fd] == NULL)
		return (NULL);
	if (is_charset(rest[fd]) == 1)
	{
		line = ft_strndup(rest[fd], '\n');
		if (line == NULL)
			return (ft_free(&rest[fd]));
		free(rest[fd]);
		rest[fd] = ft_strndup(ft_strchr(rest[fd], '\n'), '\0');
		if (rest[fd] == NULL)
			return (ft_free(&line));
		return (line);
	}
	line = ft_process(&rest[fd], fd);
	return (line);
}

/*
int	main()
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("gnl = %s", line);
		free(line);
		i++;
	}
	close(fd);
	system("leaks a.out");
	return (0);
}
*/
