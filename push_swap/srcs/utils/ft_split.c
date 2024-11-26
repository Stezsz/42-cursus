/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:40:53 by strodrig          #+#    #+#             */
/*   Updated: 2024/11/25 20:40:53 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	i = 0;
	result = malloc(sizeof(char *) * 256);
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (!*s)
			break ;
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		result[i] = malloc(j + 1);
		if (!result[i])
			return (NULL);
		k = 0;
		while (k < j)
			result[i][k++] = *s++;
		result[i++][k] = '\0';
	}
	result[i] = (NULL);
	return (result);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
