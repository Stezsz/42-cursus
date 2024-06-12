/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:35:48 by strodrig          #+#    #+#             */
/*   Updated: 2024/05/31 13:35:48 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*temp;
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;
	int			nl;

	if (!temp)
		temp = ft_strdup("");
	bytes = read(fd, buff, BUFFER_SIZE);
	while (bytes >= 0)
	{
		buff[bytes] = 0;
		temp = ft_strjoin(temp, buff);
		nl = check_newline(temp);
		if (nl != -1)
			return(func(&line, &temp, nl));
		if (!bytes && !temp[0])
			break ;
		if (!bytes)
			return (get_reminder(&temp, 0));
		bytes = read(fd, buff, BUFFER_SIZE);
	}
	free(temp);
	temp = NULL;
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
	int	i = 0;
	while(buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

/*int	main(void)
{
	int		fd = open("tester.txt", O_RDONLY);
	char	*line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return 0;
}*/
