/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:12:52 by acuva-nu          #+#    #+#             */
/*   Updated: 2022/12/09 18:35:44 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter] != '\n' && str[counter])
		counter++;
	counter += (str[counter] == '\n');
	return (counter);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		a;
	int		c;

	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	a = 0;
	c = 0;
	while (s1 && s1[a])
		res[c++] = s1[a++];
	a = -1;
	while (s2[++a] && s2[a] != '\n')
		res[c++] = s2[a];
	if (s2[a++] == '\n')
		res[c++] = '\n';
	res[c] = 0;
	free(s1);
	return (res);
}

void	bufflord(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i += (str[i] == '\n');
	while (i < BUFFER_SIZE)
	{
		str[j++] = str[i];
		str[i] = 0;
		i++;
	}
	str[j] = 0;
}

char	*reader(int fd, char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE))
	{
		line = ft_strjoin(line, buffer);
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
		{
			bufflord(buffer);
			return (line);
		}
		buffer[read(fd, buffer, BUFFER_SIZE)] = 0;
	}
	return (line);
}
