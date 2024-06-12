/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:00:11 by strodrig          #+#    #+#             */
/*   Updated: 2024/02/26 17:00:11 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c <= 122 && c >= 97)
		c -= 32;
	return (c);
}

/*#include <stdio.h>
#include <ctype.h> //Biblioteca para determinação de caracteres
int	main(void)
{
	char c = 't';

	printf("%c\n", ft_toupper(c));
	return (0);
}*/
