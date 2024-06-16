/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:56:27 by strodrig          #+#    #+#             */
/*   Updated: 2024/06/16 13:56:27 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*temp[8192];
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;
	int			nl;

	if (!temp[fd])
		temp[fd] = ft_strdup("");
	bytes = read(fd, buff, BUFFER_SIZE);
	while (bytes >= 0)
	{
		buff[bytes] = 0;
		temp[fd] = ft_strjoin(temp[fd], buff);
		nl = check_newline(temp[fd]);
		if (nl != -1)
			return (func(&line, &temp[fd], nl));
		if (!bytes && !temp[fd][0])
			break ;
		if (!bytes)
			return (get_reminder(&temp[fd], 0));
		bytes = read(fd, buff, BUFFER_SIZE);
	}
	free(temp[fd]);
	temp[fd] = NULL;
	return (NULL);
}

char	*func(char **line, char **temp, int nl)
{
	*line = ft_substr(*temp, 0, nl + 1);
	*temp = get_reminder(temp, nl + 1);
	return (*line);
}

char	*get_reminder(char **str, int nl)
{
	char	*reminder;
	int		rlen;

	rlen = ft_strlen(*str + nl);
	reminder = ft_substr(*str, nl, rlen);
	free(*str);
	*str = NULL;
	return (reminder);
}

int	check_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
