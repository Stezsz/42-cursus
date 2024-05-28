/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:30:54 by strodrig          #+#    #+#             */
/*   Updated: 2024/02/28 17:30:54 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !len)
		return (NULL);
	if (s2[0] == '\0' || s2 == s1)
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < len)
		{
			if (!s1[i + j] && !s2[j])
				return ((char *)&s1[i]);
			j++;
		}
		if (!s2[j])
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_strnstr("aaabcabcd", "cd", 8));
}*/
