/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:21:20 by naverbru          #+#    #+#             */
/*   Updated: 2022/02/08 16:00:09 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strndup(const char *str, char c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_endfree(char **str, char **buf);
char	*ft_free(char **str);
char	*ft_process(char **rest, int fd);
char	*ft_endprocess(char **line, char **buf, char ***rest);
int		is_charset(char *str);

#endif
