/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:20:32 by naverbru          #+#    #+#             */
/*   Updated: 2022/02/03 10:04:04 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define OPEN_MAX 256

void	ft_free(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}

int	is_charset(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_process(char **rest, int fd)
{
	int		ret;
	char	*line;
	char	buf[BUFFER_SIZE + 1];

	line = ft_strndup(*rest, '\n');
	ret = read(fd, &buf, BUFFER_SIZE);
	printf("buf = %s\n", buf);
	buf[ret] = '\0';
	printf("buf = %s\n", buf);
	while (ret > 0 && is_charset(buf) == 0)
	{
		line = ft_strjoin(line, buf);
		//printf("line = %s\n", line);
		ret = read(fd, &buf, BUFFER_SIZE);
		buf[ret] = '\0';
	}
	if (ret == 0)
		return (NULL);
	line = ft_strjoin(line, buf);
	*rest = ft_strndup(ft_strchr(buf, '\n'), '\0');
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	//printf("rst_debut = %s\n", rest[fd]);
	if (rest[fd] == NULL)
		rest[fd] = ft_strndup("", '\0');
	if (is_charset(rest[fd]) == 1)
	{
		line = ft_strndup(rest[fd], '\n');
		rest[fd] = ft_strndup(ft_strchr(rest[fd], '\n'), '\0');
		return (line);
	}
	line = ft_process(&rest[fd], fd);
	return (line);
}

int	main()
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("41_no_nl", O_RDONLY);
	printf("fd = %d\n", fd);
	while ((line = get_next_line(fd)))
	{
		printf("gnl = %s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
