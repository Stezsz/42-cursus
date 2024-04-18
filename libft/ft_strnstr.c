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

char	*ft_strnstr (const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s1[0] == '\0')
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j])
			{
				if (s2[j + 1] == '\0')
					return ((char *)s1 + i);
				j++;
			}
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_strnstr("asdasd1234sss", "1234", 20));
}*/
