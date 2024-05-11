/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:18:06 by strodrig          #+#    #+#             */
/*   Updated: 2024/03/15 16:18:06 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			pos;
	unsigned char	*str1;

	str1 = (unsigned char *)str;
	pos = 0;
	while (pos < n)
	{
		if ((str1)[pos] == (unsigned char)c)
			return (((unsigned char *)str1) + pos);
		pos++;
	}
	return (NULL);
}

/*#include <stdio.h>
int	main(void)
{
	char	*result;

	result = ft_memchr("test.12345", 'e', 20);

	printf("%s", result);

	return (0);
}*/
