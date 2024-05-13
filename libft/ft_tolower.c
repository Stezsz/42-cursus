/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:23:07 by strodrig          #+#    #+#             */
/*   Updated: 2024/02/26 16:23:07 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c <= 90 && c >= 65)
		c += 32;
	return (c);
}

/*#include <stdio.h>
#include <ctype.h> //Biblioteca para determinação de caracteres
int	main(void)
{
	char c = 'T';

	printf("%c\n", ft_tolower(c));
	return (0);
}*/
