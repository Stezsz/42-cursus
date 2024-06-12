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
	void	*temp;

	temp = (void *)str2;
	if (!str2 && !str1)
		return (str1);
	if (str2 > str1)
		ft_memcpy(str1, temp, n);
	else
	{
		while (n--)
			((char *)str1)[n] = ((char *)temp)[n];
	}
	return (str1);
}

/*
Se str2 > str1, vai da esquerda para a direita, pois a str1 esta na frente
Se nao, vai da direita para a esquerda para nao sobrepor
*/

/*int main(void)
{
	char str1[] = "goiaba";
	const char src[]  = "banana";

	printf("str1 = %s, src = %s\n", str1, src);
	ft_memmove(str1, src, 9);
	printf("str1 = %s, src = %s\n", str1, src);

	return(0);
}*/
