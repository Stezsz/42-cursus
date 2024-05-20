/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:56:27 by strodrig          #+#    #+#             */
/*   Updated: 2024/02/29 21:56:27 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	if (size == 0 || (size <= dest_len))
		return (ft_strlen(src) + size);
	while (src[i] && i < size - dest_len - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (ft_strlen(src) + dest_len);
}

/*#include <stdio.h>
int	main(void)
{
	char dest[10] = "Hello";
	char src[] = " World";
	printf("%lld\n", ft_strlcat(dest, src, 20));
}*/
