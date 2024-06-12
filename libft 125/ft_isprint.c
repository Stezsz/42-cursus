/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:16:55 by strodrig          #+#    #+#             */
/*   Updated: 2024/02/26 17:16:55 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c <= 126 && c >= 32)
		return (1);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h> //Biblioteca para determinação de caracteres
int	main(void)
{
	char c = 's';

	printf("%c\n", ft_isprint(c));
}*/
