/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strodrig <strodrig@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:44:30 by strodrig          #+#    #+#             */
/*   Updated: 2024/04/04 17:44:30 by strodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_len(int n)
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
	unsigned int	nbr;
	int				sign;
	int				len;
	char			*str;

	sign = 0;
	nbr = n;
	if (n < 0)
	{
		sign = 1;
		nbr = -n;
	}
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (len--)
	{
		str[len] = '0' + (nbr % 10);
		nbr /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(12345));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-456));
	printf("%s\n", ft_itoa(-2147483647));
}*/
