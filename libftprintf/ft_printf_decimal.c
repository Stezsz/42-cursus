/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:56:20 by strodrig          #+#    #+#             */
/*   Updated: 2024/04/22 17:56:20 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char(char *result, unsigned int number, int len)
{
	while (number > 0)
	{
		result[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (result);
}

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*result;
	int				len;
	unsigned int	number;
	int				sign;

	sign = 1;
	len = ft_len(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!(result))
		return (NULL);
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		result[0] = '-';
	}
	else
		number = n;
	result = ft_char(result, number, len);
	return (result);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}
