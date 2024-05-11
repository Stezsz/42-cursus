/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:35:39 by strodrig          #+#    #+#             */
/*   Updated: 2024/04/02 12:35:39 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (s);
}

/*#include <stdio.h>
int	main(void)
{
	char str[50] = "Banana&goiaba";

	printf("Before memset: %s\n", str);

	ft_memset(str, 'A', 5);

	printf("After memset: %s\n", str);

	return (0);
}*/
