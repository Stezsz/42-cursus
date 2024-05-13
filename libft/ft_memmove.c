/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:17:37 by strodrig          #+#    #+#             */
/*   Updated: 2024/03/15 19:17:37 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t			i;
	char			j;
	unsigned char	*dest;
	unsigned char	*src;

	i = 0;
	j = 1;
	dest = (unsigned char *)str1;
	src = (unsigned char *)str2;
	if (!dest || !src)
		return (NULL);
	if (dest > src)
	{
		j = -1;
		dest += n - 1;
		src += n - 1;
	}
	while (i < n)
	{
		*dest = *src;
		dest += j;
		src += j;
		i++;
	}
	return (str1);
}

/*
Se j = 1, esq para dir, se j = -1, dir para esq.
Garantir que todos os bytes se gravem se sobrepor,
dest pode sobrepor src se dest > src
*/

/*int main(void)
{
	char dest[] = "goiaba";
	const char src[]  = "banana";

	printf("dest = %s, src = %s\n", dest, src);
	ft_memmove(dest, src, 9);
	printf("dest = %s, src = %s\n", dest, src);

	return(0);
}*/
