/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 02:18:58 by discallow         #+#    #+#             */
/*   Updated: 2024/05/16 03:02:31 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while ((str1[i] || str2[i]) && i < n && str1[i] == str2[i])
		i++;
	if (n == 0 || i == n)
		return (0);
	return ((int)(unsigned char )str1[i] - (int)(unsigned char )str2[i]);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*buffer;

	buffer = malloc(n * size);
	if (buffer == NULL)
		return (NULL);
	ft_memset(buffer, 0, n * size);
	return (buffer);
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (str);
}
