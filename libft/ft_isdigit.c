/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:21:24 by strodrig          #+#    #+#             */
/*   Updated: 2024/02/27 17:21:24 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h> //Biblioteca para determinação de caracteres
int	main(void)
{
	char c = '4';

	printf("%c\n", ft_isdigit(c));
}*/
