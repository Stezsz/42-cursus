/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:56:22 by strodrig          #+#    #+#             */
/*   Updated: 2024/04/22 17:56:22 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len ++;
		n = n / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_unsigned_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (n != 0)
	{
		str[len - 1] = n % 10 + 48;
		n = n / 10;
		len --;
	}
	return (str);
}

int	ft_putunsigned(unsigned int n)
{
	int		char_printed;
	char	*str;

	char_printed = 0;
	if (n == 0)
		char_printed += write(1, "0", 1);
	else
	{
		str = ft_uitoa(n);
		char_printed += ft_putstr(str);
		free(str);
	}
	return (char_printed);
}
