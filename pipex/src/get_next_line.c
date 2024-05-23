/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:33:32 by discallow         #+#    #+#             */
/*   Updated: 2024/05/16 03:02:26 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	ft_strlen3(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

static char	*ft_strjoin3(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	buffer = (char *)malloc(ft_strlen3(s1) + ft_strlen3(s2) + 1);
	if (!buffer)
		return (NULL);
	while (s1 && s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] && s2[j] != '\n')
	{
		buffer[i + j] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
		buffer[i + j++] = '\n';
	buffer[i + j] = '\0';
	if (s1)
		free(s1);
	return (buffer);
}

void	ft_clean_buffer(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE && str[i] != '\n')
	{
		str[i] = '\0';
		i++;
	}
	if (str[i] == '\n')
	{
		str[i] = '\0';
		i++;
		while (i < BUFFER_SIZE)
		{
			str[j] = str[i];
			str[i] = '\0';
			i++;
			j++;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		while (i < BUFFER_SIZE && fd >= 0 && fd < FOPEN_MAX)
		{
			buffer[i] = '\0';
			i++;
		}
		return (NULL);
	}
	line = NULL;
	while (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0))
	{
		line = ft_strjoin3(line, buffer);
		ft_clean_buffer(buffer);
		if (line[ft_strlen3(line) - 1] == '\n')
			return (line);
	}
	return (line);
}
