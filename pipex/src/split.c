/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 02:25:07 by discallow         #+#    #+#             */
/*   Updated: 2024/05/16 03:02:53 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	*ft_free(char **str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static size_t	str_num(char const *s, char c)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (s[i] && s)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			num++;
		while (s[i] && s[i] != c)
			i++;
	}
	if (ft_strcmp((char *)s, "") == 0)
		num++;
	return (num);
}

static size_t	str_size(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*word_allocate(char const *s, char c)
{
	char	*string;
	size_t	i;
	size_t	len;

	i = 0;
	len = str_size(s, c);
	string = (char *)malloc((len + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	while (i < len)
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	index;

	index = 0;
	strs = (char **)malloc((str_num(s, c) + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			strs[index] = word_allocate(s, c);
			if (strs[index] == NULL)
				return (ft_free(strs, index));
			index++;
		}
		while (*s && *s != c)
			s++;
	}
	strs[index] = NULL;
	return (strs);
}
